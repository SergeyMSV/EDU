#pragma once

#include "TypeList_MostDerived.h"
#include "TypeList_Replace.h"
#include "TypeList_Index.h"//Test	

namespace TL
{

template <class TList, template <class> class Unit> class GenScatterHierarchy;

template <class T1, class T2, template <class> class Unit>
class GenScatterHierarchy<Typelist<T1, T2>, Unit> :
	public GenScatterHierarchy<T1, Unit>,
	public GenScatterHierarchy<T2, Unit>
{
public:
	typedef Typelist<T1, T2> TList;
	typedef GenScatterHierarchy<T1, Unit> LeftBase;
	typedef GenScatterHierarchy<T2, Unit> RightBase;

	template <typename T> struct Rebind
	{
		typedef Unit<T> Result;
	};

	template <int i> struct At
	{
		typedef typename TypeAt<LeftBase, i>::Result;
		//typedef Unit<T> Result;
	};
};

template <class AtomicType, template <class> class Unit>
class GenScatterHierarchy : public Unit<AtomicType>
{
	typedef Unit<AtomicType> LeftBase;

	template <typename T> struct Rebind
	{
		typedef Unit<T> Result;
	};

	template <> struct At
	{
		typedef typename TypeAt<LeftBase, 0>::Result;
		//typedef Unit<T> Result;
	};
};

template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit>
{
	template <typename T> struct Rebind
	{
		typedef Unit<T> Result;
	};

	template <> struct At
	{
		typedef typename TypeAt<LeftBase, 0>::Result;
		//typedef Unit<T> Result;
	};
};

}