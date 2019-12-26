#pragma once

#include "TypeList_Lists.h"

namespace TL
{

template<class TList> struct Length;

template<>
struct Length<NullType>
{
	enum { value = 0 };
};

template<class T, class U>
struct Length<Typelist<T, U>>
{
	enum { value = 1 + Length<U>::value };
};

}
