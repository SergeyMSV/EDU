/*#pragma once

#include "TypeList_Erase.h"

namespace TL
{

template <class TList> struct NoDuplicates;

template <>
struct NoDuplicates<NullType>
{
	typedef NullType Result;
};

template <class Head, class Tail>
struct NoDuplicates<Typelist<Head, Tail>>
{
private:
	typedef typename NoDuplicates<Tail>::Result L1;
	typedef typename Erase<L1, Head>::Result L2;
public:
	typedef Typelist<Head, L2> Result;
};

}*/