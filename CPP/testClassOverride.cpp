#include "testClassOverride.h"

#include <iostream>

namespace test
{

using namespace class_override;

void UnitTest_ClassOverride()
{
	std::cout << "UnitTest_ClassOverride" << std::endl;

	{
		//	tClass Class0;

		tClassBase Class1{ };//if tClass() = default; it initialized with 0 (for some unknown reason), otherwise through tClass(std::initializer_list<int> list)
		tClassBase Class2{ 4 };
		tClassBase Class3{ 4, 5 };
		tClassBase Class4{ 4, 5, 6 };

		tClassBase Class5(7, 8);

		tClassBase Class6(9, 0, "qwe");

		tClassBase Class7{ 1, 2, "ASD" };

		tClassBase Class8{ "dfgh" };

		//tClass Class9 = Class8;//tClass(tClass&) = delete;
	}

	{
		tClass4 Class{"fasadf"};

		Class.DoSomething2();

		tClassBase* ClassBasePtr = &Class;

		ClassBasePtr->DoSomething2();
	}

	{
		tClassBase* ClassBasePtr = new tClass4("fasadf");

		ClassBasePtr->DoSomething2();

		delete ClassBasePtr;
	}
}

}
