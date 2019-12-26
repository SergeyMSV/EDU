#pragma once

#include "mConvertion.h"
#include "mSelect.h"
#include "TypeList_Lists.h"

namespace TL
{

template <class TList, class T> struct MostDerived;

template <class T>
struct MostDerived<NullType, T>
{
	typedef T Result;
};

template <class Head, class Tail, class T>
struct MostDerived<Typelist<Head, Tail>, T>
{
private:
	typedef typename MostDerived<Tail, T>::Result Candidate;
public:
	typedef typename Select<Convert::tConvertion<const volatile Head*, const volatile Candidate*>::exists && !Convert::tConvertion<const volatile Candidate*, const volatile void*>::sameType, Head, Candidate>::Result Result;
	//typedef typename Select<SUPERSUBCLASS(Candidate, Head), Head, Candidate>::Result Result;
};

}