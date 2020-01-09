#include "TypeList_Replace.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_Replace()
{
	typedef TYPELIST_6(int, char, int, float, double, char) ListA;
	ListA List;

	typedef Replace<ListA, int, long>::Result TypesA;
	TypesA A;

	typedef Replace<ListA, char, long>::Result TypesB;
	TypesB B;

	typedef Replace<NullType, int, long>::Result TypesZ;
	TypesZ Z;

	std::cout << "PREVED: \n";
}

}