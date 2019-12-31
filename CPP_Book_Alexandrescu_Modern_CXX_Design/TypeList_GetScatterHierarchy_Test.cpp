#include "TypeList_GetScatterHierarchy.h"
#include "TypeList_Index.h"
#include "Int2Type.h"
#include "Type2Type.h"
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
/*
template <class H, typename R>
R& FieldHelper(H& obj, Type2Type<R> tt, Int2Type<0>)
{
	typename obj::RightBase& subobj = obj;
	return subobj;
}

template <class H, typename R, int i>
R& FieldHelper(H& obj, Type2Type<R> tt, Int2Type<i>)
{
	typename obj::RightBase& subobj = obj;
	return FieldHelper(subobj, tt, Int2Type<i - 1>());
}

template <int i, class H>
typename H::template TypeAt<i>::Result& Field(H& obj)
{
	typedef typename H::template TypeAt<i>::Result Result;

	return FieldHelper(obj, Type2Type<Result>(), Int2Type<i>());
}*/

///////////////////////////////////////////////////////////////////////////////////////////////////
template <class T, class H>
typename H::template Rebind<T>::Result& Field(H& obj)
{
	return obj;
}

//template <class H>
//typename H::template Rebind<int>::Result& Field(H& obj)
//{
//	return obj;
//}

//template <class T, class H>
//const typename H::template Rebind<T>::Result& Field(const H& obj)
//{
//	return obj;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
void UnitTest_TypeList_GetScatterHierarchy()
{
	typedef GenScatterHierarchy<TYPELIST_3(int, std::string, tWidget), Holder> WidgetInfo;
	WidgetInfo A;

	////////////////////////
	//NO SUCH TYPE OF ACCESS

	//int A1 = Field<0>(A).m_value;

	////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
	//Field<int>(A).m_value = 15;
	//Field<std::string>(A).m_value = "Preved Medved!";

	//int AA = Field<int>(A).m_value;

	Field<int>(A).m_value = 14;

	//Field(A).m_value = 15;
	//int AB = Field(A).m_value;

	//Field<WidgetInfo>(A).m_value = 16;
	//int AC = Field<WidgetInfo>(A).m_value;

	//int AA = A.m_value;//Field<0>(A).m_value;
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "PREVED: \n";
}

}