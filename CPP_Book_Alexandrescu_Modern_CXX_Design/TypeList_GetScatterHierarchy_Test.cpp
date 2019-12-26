#include "TypeList_GetScatterHierarchy.h"

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

void UnitTest_TypeList_GetScatterHierarchy()
{
	typedef GenScatterHierarchy<TYPELIST_3(int, std::string, tWidget), Holder> WidgetInfo;
	WidgetInfo A;

	std::cout << "PREVED: \n";
}

}