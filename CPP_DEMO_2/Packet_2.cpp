#include "Packet.h"
#include <algorithm>
#include <iostream>

namespace packet_2
{

///////////////////////////////////////////////////////////////////////////////////////////////////
template <class tPayload>
struct tFormatStar
{
	static const unsigned char STX = '*';

	//STX         => 1B
	//PayloadSize => 2B
	//CRC         => 2B

protected:
	static bool TryParse(const tVectorUInt8& packetVector, tFormatStar& format, tPayload& payload)
	{
		if (packetVector.size() >= GetSize(0) && packetVector[0] == STX)
		{
			unsigned short DataSize = 0;

			tVectorUInt8::const_iterator CBegin = packetVector.cbegin() + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(DataSize);

			std::copy(CBegin, CEnd, (unsigned char*)& DataSize);

			if (packetVector.size() == GetSize(DataSize)/* && CheckCRC(packetVector)*/)
			{
				CBegin = CEnd;
				CEnd += DataSize;

				payload = tPayload(CBegin, CEnd);

				return true;
			}
		}

		return false;
	}

	static size_t GetSize(size_t payloadSize) { return 5 + payloadSize; };

	void Append(tVectorUInt8& dst, const tPayload& payload) const
	{
		unsigned short CRC = 0x0304;//[TBD]

		dst.push_back(STX);

		::Append(dst, static_cast<unsigned short>(payload.GetSize()));

		payload.Append(dst);

		::Append(dst, CRC);
	}
};

template <class tPayload>
struct tFormatStar2 : public tFormatStar<tPayload>
{
	typedef unsigned char tMsgID;

private:
	tMsgID MsgID = 0;

public:
	tMsgID GetMsgID() { return MsgID; }

protected:
	static bool TryParse(const tVectorUInt8& packetVector, tFormatStar2& format, tPayload& payload)
	{
		if (packetVector.size() >= GetSize(0) && packetVector[0] == tFormatStar2::STX)
		{
			unsigned short DataSize = 0;

			tVectorUInt8::const_iterator CBegin = packetVector.cbegin() + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(DataSize);

			std::copy(CBegin, CEnd, (unsigned char*)& DataSize);

			if (packetVector.size() == GetSize(DataSize - 1)/* && CheckCRC(packetVector)*/)
			{
				CBegin = CEnd;
				CEnd += 1;

				format.MsgID = *CBegin;

				CBegin = CEnd;
				CEnd += DataSize - 1;//-MsgID

				payload = tPayload(CBegin, CEnd);
				
				return true;
			}
		}

		return false;
	}

	static size_t GetSize(size_t payloadSize) { return tFormatStar<tPayload>::GetSize(payloadSize) + 1; };

	void Append(tVectorUInt8& dst, const tPayload& payload) const
	{
		unsigned short CRC = 0x0304;//[TBD]

		dst.push_back(tFormatStar2::STX);

		::Append(dst, static_cast<unsigned short>(payload.GetSize() + 1));
		::Append(dst, MsgID);

		payload.Append(dst);

		::Append(dst, CRC);
	}
};

template <class tPayload>
struct tFormatBNTBX2
{
	static const unsigned char STX = 0x5F;

	enum class tMsgID
	{
		Msg08 = 0x08,
		Msg09,
	};
	//typedef unsigned char tMsgID;

private:
	unsigned int DeviceID = 0;
	tMsgID MsgID = tMsgID::Msg09;
	//unsigned char MsgID = 0;
	unsigned char MsgVER = 0;
	//STX         => 1B
	//PayloadSize => 2B
	//CRC         => 2B

public:
	tMsgID GetMsgID() { return MsgID; }
	unsigned char GetMsgVER() { return MsgVER; }

protected:
	static bool TryParse(const tVectorUInt8& packetVector, tFormatBNTBX2& format, tPayload& payload)
	{
		if (packetVector.size() >= GetSize(0) && packetVector[0] == STX)
		{
			tVectorUInt8::const_iterator CBegin = packetVector.cbegin() + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(format.DeviceID);

			std::copy(CBegin, CEnd, (unsigned char*)& format.DeviceID);

			CBegin = CEnd;
			CEnd += 1;

			format.MsgID = static_cast<tMsgID>(*CBegin);

			CBegin = CEnd;
			CEnd += 1;

			format.MsgVER = *CBegin;

			unsigned short PayloadSize = 0;

			CBegin = CEnd;
			CEnd += sizeof(PayloadSize);

			std::copy(CBegin, CEnd, (unsigned char*)& PayloadSize);

			if (packetVector.size() == GetSize(PayloadSize)/* && CheckCRC(packetVector)*/)
			{
				CBegin = CEnd;
				CEnd += PayloadSize;
				
				payload = tPayload(CBegin, CEnd);

				return true;
			}			
		}

		return false;
	}

	static size_t GetSize(size_t payloadSize) { return 11 + payloadSize; };

	void Append(tVectorUInt8& dst, const tPayload& payload) const
	{
		unsigned short CRC = 0x0304;//[TBD]

		dst.push_back(STX);

		::Append(dst, DeviceID);

		dst.push_back(static_cast<unsigned char>(MsgID));
		dst.push_back(MsgVER);

		::Append(dst, static_cast<unsigned short>(payload.GetSize() + 1));

		payload.Append(dst);

		::Append(dst, CRC);
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////
struct tPayload
{
	tVectorUInt8 Data;

	tPayload() { }

	tPayload(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend)
	{
		Data.insert(Data.end(), cbegin, cend);
	}
//protected:
	//static bool TryParse(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend, tPayload& packet)
	//{
	//	packet.Data.insert(packet.Data.end(), cbegin, cend);

	//	return true;
	//}

	size_t GetSize() const { return Data.size(); };

	void Append(tVectorUInt8& dst) const
	{
		dst.insert(dst.end(), Data.cbegin(), Data.cend());
	}
};

struct tMsgBNTBX0802
{
	unsigned char CERR;

	explicit tMsgBNTBX0802(unsigned char cerr)
	{
		CERR = cerr;
	}

	explicit tMsgBNTBX0802(const tVectorUInt8 payload)
	{
		if (payload.size() == 1)
		{
			CERR = payload[0];
		}
		else
		{
			throw std::invalid_argument::exception("tMsgBNTBX0802");
		}
	}

	static size_t GetSize() { return 1; };

	tVectorUInt8 ToVector() const
	{
		tVectorUInt8 MsgVector;

		MsgVector.push_back(CERR);

		return MsgVector;
	}
};

//struct tMsg1
//{
//	int A = 1;
//	int B = 2;
//	int C = 3;
//	int D = 4;
//
//	size_t GetPayloadSize() const { return sizeof(*this); };
//
//	void Append(tVectorUInt8& dst) const
//	{
//		::Append(dst, A);
//		::Append(dst, B);
//		::Append(dst, C);
//		::Append(dst, D);
//	}
//};
///////////////////////////////////////////////////////////////////////////////////////////////////
template
<
template <class> class tFormat,
class tPayload
>
class tPacket : public tFormat<tPayload>, tPayload
{
public:
	tPacket() { }

	//static tPacket Make()

	static bool TryParse(const tVectorUInt8& packetVector, tPacket& packet)
	{
		return tFormat<tPayload>::TryParse(packetVector, packet, packet);
	}

	template <class tMsg>
	tMsg GetMsg() const
	{
		return tMsg(tPayload::Data);
	}

	template <class tMsg>
	void SetMsg(const tMsg& msg)
	{
		tPayload::Data = msg.ToVector();
	}

	tVectorUInt8 ToVector()
	{
		size_t PayloadSize = tPayload::GetSize();

		size_t PacketSize = tFormat<tPayload>::GetSize(PayloadSize);

		tVectorUInt8 PacketVector;

		PacketVector.reserve(PacketSize);

		tFormat<tPayload>::Append(PacketVector, *this);
		
		return PacketVector;
	}
};

typedef tPacket<tFormatStar, tPayload> tPacketStar;
typedef tPacket<tFormatStar2, tPayload> tPacketStar2;
typedef tPacket<tFormatBNTBX2, tPayload> tPacketBNTBX2;

}

void Packet_2()
{
	using namespace packet_2;

	{
		tPacketStar Packet;

		//Packet.

		tVectorUInt8 PacketVector = Packet.ToVector();
	}

	{
		tVectorUInt8 Data{ 0x2A, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0xB0, 0x8D };

		tPacketStar Packet;

		if (tPacketStar::TryParse(Data, Packet))
		{
			std::cout << "tPacketStar::TryParse() OK\n";
		}
	}

	{
		tPacketStar2 Packet;

		//Packet.

		tVectorUInt8 PacketVector = Packet.ToVector();
	}

	{
		tVectorUInt8 Data{ 0x2A, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0xB0, 0x8D };

		tPacketStar2 Packet;

		if (tPacketStar2::TryParse(Data, Packet))
		{
			std::cout << "tPacketStar2::TryParse() OK\n";
		}
	}

	{
		tPacketBNTBX2 Packet;

		tMsgBNTBX0802 Msg(0x25);

		Packet.SetMsg<tMsgBNTBX0802>(Msg);

		tVectorUInt8 PacketVector = Packet.ToVector();
	}

	{
		tVectorUInt8 Data{ 0x5F, 0x66, 0x00, 0x00, 0x00, 0x08, 0x02, 0x01, 0x00, 0x00, 0xAA, 0x62 };

		


		tPacketBNTBX2 Packet;

		if (tPacketBNTBX2::TryParse(Data, Packet))
		{
			std::cout << "tPacketBNTBX2::TryParse() OK\n";

			switch (Packet.GetMsgID())
			{
			case tPacketBNTBX2::tMsgID::Msg08:
			{
				switch (Packet.GetMsgVER())
				{
				case 0x02:
				{
					try
					{
						tMsgBNTBX0802 Msg = Packet.GetMsg<tMsgBNTBX0802>();

						std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() OK\n";
					}
					catch (std::invalid_argument::exception ex)
					{
						std::cout << "tPacketBNTBX2::GetMsg<tPayloadBNTBX0802>() ER: " << ex.what() << '\n';
					}

					break;
				}
				}

				break;
			}
			}

		}
	}
}
