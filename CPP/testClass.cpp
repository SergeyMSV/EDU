#include "testClass.h"

#include <iostream>

namespace test
{

void UnitTest_tClass()
{
	std::cout << "UnitTest_tClass" << std::endl;

//	tClass Class0;

	tClass Class1{ };//if tClass() = default; it initialized with 0 (for some unknown reason), otherwise through tClass(std::initializer_list<int> list)
	tClass Class2{ 4 };
	tClass Class3{ 4, 5 };
	tClass Class4{ 4, 5, 6 };

	tClass Class5(7, 8);

	tClass Class6(9, 0, "qwe");

	tClass Class7{ 1, 2, "ASD" };

	tClass Class8{ "dfgh" };

	//tClass Class9 = Class8;//tClass(tClass&) = delete;
}

}
