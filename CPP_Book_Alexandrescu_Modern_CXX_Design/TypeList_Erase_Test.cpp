#include "TypeList_Erase.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_Erase()
{
	typedef TYPELIST_6(char, short, int, int, long, int, double, long double) ListA;

	typedef Erase<ListA, float>::Result TypesA;
	TypesA A;

	typedef Erase<ListA, char>::Result TypesB;
	TypesB B;

	std::cout << "PREVED: \n";
}

}