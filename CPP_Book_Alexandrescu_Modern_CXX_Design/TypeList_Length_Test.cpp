#include "TypeList_Length.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_Length()
{
	typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;

	auto SignedIntegralsSize = Length<SignedIntegrals>::value;

	std::cout << "TL: " << SignedIntegralsSize << '\n';

	typedef Typelist<char, Typelist<int, NullType>> CharList;

	auto CharListSize = Length<CharList>::value;

	std::cout << "TL: " << CharListSize << '\n';

	std::type_info* instRtti[Length<SignedIntegrals>::value];

	std::cout << "PREVED: \n";
}

}