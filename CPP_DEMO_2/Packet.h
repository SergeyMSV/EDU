#pragma once

#include <vector>

typedef std::vector<unsigned char> tVectorUInt8;

//template<typename T, typename Iterator>
//T Read(Iterator first, Iterator last)
//{
//	T Data = 0;
//
//	int Size = std::distance(first, last);
//
//	if (Size <= sizeof(T))
//	{
//		std::copy(first, last, (unsigned char*)& Data);
//	}
//
//	return Data;
//}

template<typename T>//[TBD]Check that T is a value-type containing no iterators.
inline void Append(tVectorUInt8& dst, const T& value)
{
	dst.insert(dst.end(), (unsigned char*)& value, ((unsigned char*)& value) + sizeof(value));
}