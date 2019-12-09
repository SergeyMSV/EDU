#include "Packet.h"

namespace packet_1
{

//template <class T>
class tConfig
{
	//m_MemoryPtr

	int m_Value1 = 0;

public:
	int GetValue1() { return m_Value1; }
	void SetValue1(int value) { m_Value1 = value; }
};
///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)
struct tHeaderStar
{
	unsigned short PayloadSize = 0;

	size_t GetHeaderSize() const { return sizeof(*this); };

	void Append(tVectorUInt8& dst) const
	{
		::Append(dst, PayloadSize);
	}
};

struct tHeaderStarMsgID : public tHeaderStar
{
	unsigned char MsgID = 0;

	size_t GetHeaderSize() const { return sizeof(*this); };

	void Append(tVectorUInt8& dst) const
	{
		tHeaderStar::Append(dst);
		::Append(dst, PayloadSize);
	}
};

struct tHeaderBNTBX2
{
	unsigned int DeviceID = 0;
	unsigned char MsgID = 0;
	unsigned char MsgVersion = 0;
	//unsigned short PayloadSize;
	//unsigned short PayloadSize = 0;

	size_t GetHeaderSize() const { return sizeof(*this); };

	void Append(tVectorUInt8& dst) const
	{
		::Append(dst, DeviceID);
		::Append(dst, MsgID);
		::Append(dst, MsgVersion);
	}
};
#pragma pack()
///////////////////////////////////////////////////////////////////////////////////////////////////
struct tPayload
{
	tVectorUInt8 Data;

	size_t GetPayloadSize() const { return Data.size(); };

	void Append(tVectorUInt8& dst) const
	{
		::Append(dst, Data);
	}
};

struct tMsg1
{
	int A = 1;
	int B = 2;
	int C = 3;
	int D = 4;

	size_t GetPayloadSize() const { return sizeof(*this); };

	void Append(tVectorUInt8& dst) const
	{
		::Append(dst, A);
		::Append(dst, B);
		::Append(dst, C);
		::Append(dst, D);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////
struct tCRC16
{
	size_t GetCheckSize() const { return 2; };

	void Append(tVectorUInt8& dst, tVectorUInt8::const_iterator begin, tVectorUInt8::const_iterator end) const
	{
		unsigned short CRC = 0x2C4B;//[TBD]Get real CRC

		::Append(dst, CRC);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////
template
<
	class tHeader,
	class tPayload,
	class tCheckingPolicy//,
	/*template <class>*/ //class tStoragePolicy
>
class tPacket : public tHeader, public tPayload, public tCheckingPolicy//,  public tStoragePolicy
{
public:
	tPacket() { }

	tVectorUInt8 ToVector()
	{
		size_t HeaderSize = tHeader::GetHeaderSize();
		size_t PayloadSize = tPayload::GetPayloadSize();

		size_t Size = 1 + HeaderSize + PayloadSize + tCheckingPolicy::GetCheckSize();//1 => STX

		tVectorUInt8 PacketVector;

		PacketVector.reserve(Size);

		PacketVector.push_back('*');//NOT GOOD

		tHeader::Append(PacketVector);
		tPayload::Append(PacketVector);
		tCheckingPolicy::Append(PacketVector, PacketVector.cbegin(), PacketVector.cend());

		return PacketVector;
	};
};

typedef tPacket<tHeaderStar, tPayload, tCRC16> tPacketStar;
typedef tPacket<tHeaderStarMsgID, tPayload, tCRC16> tPacketStar2;
typedef tPacket<tHeaderBNTBX2, tPayload, tCRC16> tPacketBNTBX2;

}

void Packet_1()
{
	using namespace packet_1;

	tPacketStar PackStar1;

	PackStar1.PayloadSize = 21;
	//PackStar1.

	//PackStar1.SetValue1(21);
	//int Value1 = PackStar1.GetValue1();

	size_t PackStar1HeaderSize = PackStar1.GetHeaderSize();

	tVectorUInt8 PackStar1Vector = PackStar1.ToVector();


	//tPacketStar2 PackStar2;

	//PackStar2.MsgID = 123;

	//tVectorUInt8 PackStar2Vector = PackStar2.ToVector();
}