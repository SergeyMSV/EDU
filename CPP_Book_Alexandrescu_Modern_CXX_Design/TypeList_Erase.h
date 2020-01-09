#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T> struct Erase;

template <class T>
struct Erase <NullType, T>
{
	typedef NullType Result;
};

template <class T, class Tail>
struct Erase<Typelist<T, Tail>, T>
{
	typedef Tail Result;
};

template <class Head, class Tail, class T>
struct Erase<Typelist<Head, Tail>, T>
{
	typedef Typelist<Head, typename Erase<Tail, T>::Result> Result;
};

}