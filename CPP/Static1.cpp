#include "Static.h"

#include <iostream>

namespace test
{

int tClass_Static_1::X = 12;//определяем статическую переменную-член

//if there is no "static": "Linker error: already defined"
static void FooStaticLocal()
{
	std::cout << "FooStaticLocal 1" << std::endl;
}

void UnitTest_Static1()
{
	std::cout << "UnitTest_Static1" << std::endl;

	FooStatic();

	FooStaticLocal();
	////////////////////////////////////////////////////////////////////
	int Xa = tClass_Static_1::X;

	tClass_Static_1::X++;

	int Xb = tClass_Static_1::X;

	tClass_Static_1 A;

	int Xc = A.X;

	std::cout << Xa << " " << Xb << " " << Xc << std::endl;
	////////////////////////////////////////////////////////////////////
}

}