#include "TypeList_ReplaceAll.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_ReplaceAll()
{
	typedef TYPELIST_6(int, char, int, float, double, char) ListA;
	ListA List;

	typedef ReplaceAll<ListA, int, long>::Result TypesA;
	TypesA A;

	typedef ReplaceAll<ListA, char, long>::Result TypesB;
	TypesB B;

	typedef ReplaceAll<NullType, int, long>::Result TypesZ;
	TypesZ Z;

	std::cout << "PREVED: \n";
}

}