#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T, class U> struct ReplaceAll;

template <class T, class U>
struct ReplaceAll<NullType, T, U>
{
	typedef NullType Result;
};

template <class T, class Tail, class U>
struct ReplaceAll<Typelist<T, Tail>, T, U>
{
	typedef Typelist<U, typename ReplaceAll<Tail, T, U>::Result> Result;
};

template <class Head, class Tail, class T, class U>
struct ReplaceAll<Typelist<Head, Tail>, T, U>
{
	typedef Typelist<Head, typename ReplaceAll<Tail, T, U>::Result> Result;
};

}