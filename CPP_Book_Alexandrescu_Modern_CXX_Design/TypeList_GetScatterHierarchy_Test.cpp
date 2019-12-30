#include "TypeList_GetScatterHierarchy.h"
#include "TypeList_Index.h"
//#include "mConversion.h"

#include <iostream>

#include <string>

struct tWidget
{};

template <class T>
struct Holder
{
	T m_value;
};

namespace TL
{
/*	template <class H, unsigned int i> struct FieldHelper;

	template <class H>
	struct FieldHelper<H, 0>
	{
		typedef typename H::TList::Head ElementType;
		typedef typename H::template Rebind<ElementType>::Result UnitType;

		enum
		{
			isTuple = Convert::tConversion<UnitType, TupleUnit<ElementType> >::sameType,
			isConst = TypeTraits<H>::isConst
		};

		typedef const typename H::LeftBase ConstLeftBase;

		typedef typename IntSelect<isConst, ConstLeftBase,
			typename H::LeftBase>::Result LeftBase;

		typedef typename IntSelect<isTuple, ElementType,
			UnitType>::Result UnqualifiedResultType;

		typedef typename IntSelect<isConst, const UnqualifiedResultType,
			UnqualifiedResultType>::Result ResultType;

		static ResultType& Do(H& obj)
		{
			LeftBase& leftBase = obj;
			return leftBase;
		}
	};

	template <class H, unsigned int i>
	struct FieldHelper
	{
		typedef typename TL::TypeAt<typename H::TList, i>::Result ElementType;
		typedef typename H::template Rebind<ElementType>::Result UnitType;

		enum
		{
			isTuple = Convert::tConversion<UnitType, TupleUnit<ElementType> >::sameType,
			isConst = TypeTraits<H>::isConst
		};

		typedef const typename H::RightBase ConstRightBase;

		typedef typename IntSelect<isConst, ConstRightBase,
			typename H::RightBase>::Result RightBase;

		typedef typename IntSelect<isTuple, ElementType,
			UnitType>::Result UnqualifiedResultType;

		typedef typename IntSelect<isConst, const UnqualifiedResultType,
			UnqualifiedResultType>::Result ResultType;

		static ResultType& Do(H& obj)
		{
			RightBase& rightBase = obj;
			return FieldHelper<RightBase, i - 1>::Do(rightBase);
		}
	};


template <int i, class H>
typename FieldHelper<H, i>::ResultType&	Field(H& obj)
{
	return FieldHelper<H, i>::Do(obj);
}*/


template <class T, class H>
typename H::template Rebind<T>::Result& Field(H& obj)
{
	return obj;
}

template <class H>
typename H::template Rebind<int>::Result& Field(H& obj)
{
	return obj;
}

//template <class T, class H>
//const typename H::template Rebind<T>::Result& Field(const H& obj)
//{
//	return obj;
//}

void UnitTest_TypeList_GetScatterHierarchy()
{
	typedef GenScatterHierarchy<TYPELIST_3(int, std::string, tWidget), Holder> WidgetInfo;
	WidgetInfo A;

	//typedef typename TYPELIST_3(int, float, char) ListA;
	//typedef typename TypeAt<ListA, 1>::Result ElementType;
	//ElementType E;

	//Holder<int>

	//Field<int>(A).m_value = 15;
	//Field<std::string>(A).m_value = "Preved Medved!";

	//int AA = Field<int>(A).m_value;

	Field<int, WidgetInfo>(A).m_value = 14;

	Field(A).m_value = 15;
	int AB = Field(A).m_value;

	//Field<WidgetInfo>(A).m_value = 16;
	//int AC = Field<WidgetInfo>(A).m_value;

	//int AA = A.m_value;//Field<0>(A).m_value;

	std::cout << "PREVED: \n";
}

}