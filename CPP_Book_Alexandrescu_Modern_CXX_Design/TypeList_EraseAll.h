#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T> struct EraseAll;

template <class T>
struct EraseAll<NullType, T>
{
	typedef NullType Result;
};

template <class T, class Tail>
struct EraseAll<Typelist<T, Tail>, T>
{
	typedef typename EraseAll<Tail, T>::Result Result;
};

template <class Head, class Tail, class T>
struct EraseAll<Typelist<Head, Tail>, T>
{
	typedef Typelist<Head, typename EraseAll<Tail, T>::Result> Result;
};

}