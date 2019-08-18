#pragma once

#include "PacketStar.h"

template <class TPayload>
struct tFormatStar2 : public tFormatStar<TPayload>
{
	typedef unsigned char tMsgID;

private:
	tMsgID MsgID = 0;

public:
	tMsgID GetMsgID() { return MsgID; }

protected:
	static tVectorUInt8 TestPacket(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend)
	{
		size_t Size = std::distance(cbegin, cend);

		if (Size >= GetSize(0) && *cbegin == tFormatStar2::STX)
		{
			unsigned short DataSize = 0;

			tVectorUInt8::const_iterator CBegin = cbegin + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(DataSize);

			std::copy(CBegin, CEnd, reinterpret_cast<tUInt8*>(&DataSize));

			if (Size >= GetSize(DataSize - 1))
			{
				//Get CRC
				//if (CheckCRC(packetVector))

				return tVectorUInt8(cbegin, cbegin + GetSize(DataSize - 1));
			}
		}

		return tVectorUInt8();
	}

	static bool TryParse(const tVectorUInt8& packetVector, tFormatStar2& format, TPayload& payload)
	{
		if (packetVector.size() >= GetSize(0) && packetVector[0] == tFormatStar2::STX)
		{
			unsigned short DataSize = 0;

			tVectorUInt8::const_iterator CBegin = packetVector.cbegin() + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(DataSize);

			std::copy(CBegin, CEnd, reinterpret_cast<tUInt8*>(&DataSize));

			if (packetVector.size() == GetSize(DataSize - 1))
			{
				//Get CRC
				//if (CheckCRC(packetVector))

				CBegin = CEnd;
				CEnd += 1;

				format.MsgID = *CBegin;

				CBegin = CEnd;
				CEnd += DataSize - 1;//-MsgID

				payload = TPayload(CBegin, CEnd);

				return true;
			}
		}

		return false;
	}

	static size_t GetSize(size_t payloadSize) { return tFormatStar<TPayload>::GetSize(payloadSize) + 1; };

	void Append(tVectorUInt8& dst, const TPayload& payload) const
	{
		unsigned short CRC = 0x0304;//[TBD]

		dst.push_back(tFormatStar2::STX);

		utils::Append(dst, static_cast<unsigned short>(payload.GetSize() + 1));
		utils::Append(dst, MsgID);

		payload.Append(dst);

		utils::Append(dst, CRC);
	}
};

typedef utils::tPacket<tFormatStar2, utils::tPayloadSIMPLE> tPacketStar2;
