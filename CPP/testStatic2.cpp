#include "testStatic.h"

#include <iostream>

namespace test
{

//if there is no "static": "Linker error: already defined"
static void FooStaticLocal()
{
	std::cout << "FooStaticLocal 2" << std::endl;
}

void UnitTest_Static2()
{
	std::cout << "UnitTest_Static2" << std::endl;

	//std::cout << gX << " " << gXConst << std::endl;

	FooStatic();

	FooStaticLocal();
}

}