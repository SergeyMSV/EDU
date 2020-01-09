#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template <class TList, unsigned int index> struct TypeAt;

template <class Head, class Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
	typedef Head Result;
};

template <class Head, class Tail, unsigned int index>
struct TypeAt<Typelist<Head, Tail>, index>
{
	typedef typename TypeAt<Tail, index - 1>::Result Result;
};

}