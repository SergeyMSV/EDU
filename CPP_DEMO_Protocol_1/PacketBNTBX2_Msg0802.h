#pragma once

#include "Packet.h"

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
			throw std::exception("tMsgBNTBX0802");//[TBD] Invalid argument
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