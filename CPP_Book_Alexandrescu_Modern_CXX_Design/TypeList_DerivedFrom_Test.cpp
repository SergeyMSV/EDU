/*#include "TypeList_NoDuplicates.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_NoDuplicates()
{
	typedef TYPELIST_6(int, char, int, float, double, char) ListA;
	ListA List;

	typedef NoDuplicates<ListA>::Result TypesA;
	TypesA A;

	typedef NoDuplicates<NullType>::Result TypesB;
	TypesB B;

	std::cout << "PREVED: \n";
}

}*/