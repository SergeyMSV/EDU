#include "testStruct.h"

#include <iostream>

namespace test
{

void UnitTest_tStruct()
{
	std::cout << "UnitTest_tStruct" << std::endl;

	tStruct Struct{ 4, "four" };

	tStruct Struct2{ 5, "five", 3.4 };

	std::cout << Struct.A << " " << Struct.B << std::endl;
}

}
