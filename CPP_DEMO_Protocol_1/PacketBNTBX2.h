#pragma once

#include "Packet.h"

template <class tPayload>
struct tFormatBNTBX2
{
	static const unsigned char STX = 0x5F;

	enum class tMsgID
	{
		Msg08 = 0x08,
		Msg09,
	};

private:
	unsigned int DeviceID = 0;
	tMsgID MsgID = tMsgID::Msg09;
	unsigned char MsgVER = 0;
	//STX         => 1B
	//PayloadSize => 2B
	//CRC         => 2B

public:
	tMsgID GetMsgID() { return MsgID; }
	unsigned char GetMsgVER() { return MsgVER; }

protected:
	static tVectorUInt8 TestPacket(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend)
	{
		size_t Size = std::distance(cbegin, cend);

		if (Size >= GetSize(0) && *cbegin == STX)
		{
			unsigned short PayloadSize = 0;

			tVectorUInt8::const_iterator CBegin = cbegin + 7;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(PayloadSize);

			std::copy(CBegin, CEnd, (unsigned char*)& PayloadSize);

			if (Size >= GetSize(PayloadSize)/* && CheckCRC(packetVector.begin(), end;)*/)
			{
				return tVectorUInt8(cbegin, cbegin + GetSize(PayloadSize));
			}
		}

		return tVectorUInt8();
	}

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

typedef tPacket<tFormatBNTBX2, tPayload> tPacketBNTBX2;
