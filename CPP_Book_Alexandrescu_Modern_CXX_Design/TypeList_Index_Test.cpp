#include "TypeList_Index.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_Index()
{
	typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;

	TypeAt<SignedIntegrals, 0>::Result A0;
	TypeAt<SignedIntegrals, 1>::Result A1;
	TypeAt<SignedIntegrals, 2>::Result A2;
	//TypeAt<SignedIntegrals, 3>::Result A3;//ERROR

	std::cout << "PREVED: \n";
}

}