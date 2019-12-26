#include "TypeList_IndexOf.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_IndexOf()
{
	typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;

	int Short = IndexOf<SignedIntegrals, short>::value;
	int Int = IndexOf<SignedIntegrals, int>::value;
	int Long = IndexOf<SignedIntegrals, long>::value;

	int TestA = IndexOf<SignedIntegrals, char>::value;
	int TestB = IndexOf<SignedIntegrals, NullType>::value;

	std::cout << "UnitTest_TypeList_IndexOf: "<<Short<<" "<<Int<<"\n";
}

}