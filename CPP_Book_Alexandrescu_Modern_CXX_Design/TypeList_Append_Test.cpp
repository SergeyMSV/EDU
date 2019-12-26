#include "TypeList_Append.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_Append()
{
	typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;

	typedef Append<SignedIntegrals, char>::Result TypesA;
	TypesA A;

	typedef Append<SignedIntegrals, TYPELIST_3(float, double, long double)>::Result TypesSigned;
	TypesSigned B;

	////////////////////////////
	//Every example for every case of template specialization

	typedef Append<NullType, NullType>::Result TypesN1;
	TypesN1 N1;

	typedef Append<NullType, char>::Result TypesN2;
	TypesN2 N2;

	typedef Append<NullType, Typelist<int, float>>::Result TypesN3;
	TypesN3 N3;

	typedef Append<Typelist<int, NullType>, char>::Result TypesN4;
	TypesN4 N4;

	//One of the types shall be NullType by all means...
	//further 4 examples are wrong:

	//typedef Append<char>::Result TypesA1;
	//TypesA1 A1;

	//typedef Append::Result TypesA2;
	//TypesA2 A2;

	//typedef Append<int, char>::Result TypesA3;
	//TypesA3 A3;

	//typedef Append<Typelist<int, float>, char>::Result TypesA4;
	//TypesA4 A4;

	std::cout << "PREVED: \n";
}

}