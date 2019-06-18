#pragma once

#include <exception>
#include <vector>
///////////////////////////////////////////////////////////////////////////////////////////////////
typedef std::vector<unsigned char> tVectorUInt8;
///////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>//[TBD]Check that T is a value-type containing no iterators.
inline void Append(tVectorUInt8& dst, const T& value)
{
	dst.insert(dst.end(), (unsigned char*)& value, ((unsigned char*)& value) + sizeof(value));
}
///////////////////////////////////////////////////////////////////////////////////////////////////

//[TBD]Exceptions

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

	static bool Find(tVectorUInt8& receivedData, tPacket& packet)
	{
		tVectorUInt8::const_iterator Begin = receivedData.cbegin();

		for (;;)
		{
			Begin = std::find(Begin, receivedData.cend(), tFormat<tPayload>::STX);

			if (Begin == receivedData.cend())
			{
				break;
			}

			tVectorUInt8 PacketVector = tFormat<tPayload>::TestPacket(Begin, receivedData.cend());

			if (PacketVector.size() > 0)
			{
				if (TryParse(PacketVector, packet))
				{
					size_t EraseSize = std::distance(receivedData.cbegin(), Begin);

					EraseSize += PacketVector.size();

					receivedData.erase(receivedData.begin(), receivedData.begin() + EraseSize);

					return true;
				}
			}

			Begin++;
		}

		return false;
	}

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
///////////////////////////////////////////////////////////////////////////////////////////////////
struct tPayload
{
	tVectorUInt8 Data;

	tPayload() { }

	tPayload(tVectorUInt8::const_iterator cbegin, tVectorUInt8::const_iterator cend)
	{
		Data.insert(Data.end(), cbegin, cend);
	}

	size_t GetSize() const { return Data.size(); };

	void Append(tVectorUInt8& dst) const
	{
		dst.insert(dst.end(), Data.cbegin(), Data.cend());
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////