#pragma once

#include "Packet.h"

template <class tPayload>
struct tFormatStar
{
	static const unsigned char STX = '*';

	//STX         => 1B
	//PayloadSize => 2B
	//CRC         => 2B

protected:
	static tVectorUInt8 TestPacket(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend)
	{
		size_t Size = std::distance(cbegin, cend);

		if (Size >= GetSize(0) && *cbegin == STX)
		{
			unsigned short DataSize = 0;

			tVectorUInt8::const_iterator CBegin = cbegin + 1;
			tVectorUInt8::const_iterator CEnd = CBegin + sizeof(DataSize);

			std::copy(CBegin, CEnd, (unsigned char*)& DataSize);

			if (Size >= GetSize(DataSize)/* && CheckCRC(packetVector.begin(), end;)*/)
			{
				return tVectorUInt8(cbegin, cbegin + GetSize(DataSize));
			}
		}

		return tVectorUInt8();
	}

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

typedef tPacket<tFormatStar, tPayload> tPacketStar;
