#include "TypeList_EraseAll.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_EraseAll()
{
	typedef  TYPELIST_6(char, short, int, int, long, int, double, long double) ListA;

	typedef EraseAll<ListA, float>::Result TypesA;
	TypesA A;

	typedef EraseAll<ListA, char>::Result TypesB;
	TypesB B;

	typedef EraseAll<ListA, int>::Result TypesC;
	TypesC C;

	std::cout << "PREVED: \n";
}

}