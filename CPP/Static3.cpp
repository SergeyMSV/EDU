#include "Static.h"

#include <iostream>

namespace test
{

//if there is no "static": "Linker error: already defined"
static void FooStaticLocal()
{
	std::cout << "FooStaticLocal 3" << std::endl;
}

void UnitTest_Static3()
{
	std::cout << "UnitTest_Static3" << std::endl;

	//std::cout << gX << " " << gXConst << std::endl;

	FooStatic();

	FooStaticLocal();
}

}