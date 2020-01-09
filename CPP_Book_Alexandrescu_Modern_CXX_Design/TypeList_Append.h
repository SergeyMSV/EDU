#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T> struct Append;

template <>
struct Append<NullType, NullType>
{
	typedef NullType Result;
};

template <class T>
struct Append<NullType, T>
{
	typedef TYPELIST_1(T) Result;
};

template <class Head, class Tail>
struct Append<NullType, Typelist<Head, Tail>>
{
	typedef Typelist<Head, Tail> Result;
};

template <class Head, class Tail, class T>
struct Append<Typelist<Head, Tail>, T>
{
	typedef Typelist<Head, typename Append<Tail, T>::Result> Result;
};

}