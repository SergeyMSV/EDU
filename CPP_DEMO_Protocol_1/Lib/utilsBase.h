///////////////////////////////////////////////////////////////////////////////////////////////////
// utilsBase.h
//
// Standard ISO/IEC 114882, C++98
//
// |   version  |    release    | Description
// |------------|---------------|---------------------------------
// |      1     |   2019 08 18  |
// |            |               | 
///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector>

namespace utils
{

typedef unsigned char tUInt8;
typedef std::vector<tUInt8> tVectorUInt8;

template<typename T>
typename std::enable_if<std::is_trivially_copyable<T>::value, void>::type Append(tVectorUInt8& dst, const T& value)
{
	const unsigned char* Begin = reinterpret_cast<const tUInt8*>(&value);

	dst.insert<const tUInt8*>(dst.end(), Begin, Begin + sizeof(value));
}

template<typename T>
typename std::enable_if<std::is_trivially_copyable<T>::value, tVectorUInt8>::type ToVector(const T& value)
{
	std::vector<char> Data;

	Data.reserve(sizeof(value));

	const unsigned char* Begin = reinterpret_cast<const tUInt8*>(&value);

	Data.insert(Data.end(), Begin, Begin + sizeof(value));

	return Data;
}

template<typename T, typename Iterator>
typename std::enable_if<std::is_trivially_copyable<T>::value, T>::type Read(Iterator first, Iterator last)
{
	T Data = 0;

	int Size = std::distance(first, last);

	if (Size <= sizeof(T))
	{
		std::copy(first, last, reinterpret_cast<tUInt8*>(&Data));
	}

	return Data;
}

template<typename T>
typename std::enable_if<std::is_trivially_copyable<T>::value, T>::type Read(const char* data, size_t dataSize)
{
	return Read<T, const char*>(data, data + dataSize);
}

template<typename T>
typename std::enable_if<std::is_trivially_copyable<T>::value, T>::type Reverse(T value)
{
	char* Begin = reinterpret_cast<char*>(&value);

	std::reverse<char*>(Begin, Begin + sizeof(value));

	return value;
}

}
