#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T> struct IndexOf;

template <class T>
struct IndexOf<NullType, T>
{
	enum { value = -1 };
};

template <class T, class Tail>
struct IndexOf<Typelist<T, Tail>, T>
{
	enum { value = 0 };
};

template <class Head, class Tail, class T>
struct IndexOf<Typelist<Head, Tail>, T>
{
private:
	enum { temp = IndexOf<Tail, T>::value };

public:
	enum { value = temp == -1 ? -1 : 1 + temp };
};

}