#pragma once

#include "TypeList_MostDerived.h"
#include "TypeList_Replace.h"

namespace TL
{

template <class TList> struct DerivedToFront;

template <>
struct DerivedToFront<NullType>
{
	typedef NullType Result;
};

template <class Head, class Tail>
struct DerivedToFront<Typelist<Head, Tail>>
{
private:
	typedef typename MostDerived<Tail, Head>::Result TheMostDerived;
	typedef typename Replace<Tail, TheMostDerived, Head>::Result Temp;
	typedef typename DerivedToFront<Temp>::Result L;
public:
	typedef Typelist<TheMostDerived, L> Result;
};

}