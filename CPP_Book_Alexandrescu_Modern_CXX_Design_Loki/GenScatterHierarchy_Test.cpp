#include "Loki/HierarchyGenerators.h"

#include <iostream>

struct tWidget
{};

template <class T>
struct Holder
{
	T m_value;
};

void UnitTest_GenScatterHierarchy()
{
	typedef Loki::GenScatterHierarchy<TYPELIST_3(int, std::string, tWidget), Holder> WidgetInfo;
	WidgetInfo A;

	int AA = Loki::Field<0>(A).m_value;

	std::cout << "GenScatterHierarchy-end\n";
}