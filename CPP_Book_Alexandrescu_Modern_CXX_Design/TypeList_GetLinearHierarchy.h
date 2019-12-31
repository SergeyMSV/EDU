#pragma once

#include "EmptyType.h"
#include "TypeList_MostDerived.h"
#include "TypeList_Replace.h"
#include "TypeList_Index.h"//Test	

namespace TL
{

template
<
	class TList,
	template <class AtomicType, class Base> class Unit,
	class Root = EmptyType
>
class GenLinearHierarchy;

template
<
	class T1,
	class T2,
	template <class, class> class Unit,
	class Root
>
class GenLinearHierarchy<Typelist<T1, T2>, Unit, Root>
	:public Unit<T1, GenLinearHierarchy<T2, Unit, Root>>
{

};

template
<
	class T,
	template <class, class> class Unit,
	class Root
>
//class GenLinearHierarchy<TYPELIST_1(T), Unit, Root>
class GenLinearHierarchy<Typelist<T, NullType>, Unit, Root>
	:public Unit<T, Root>
{

};

}