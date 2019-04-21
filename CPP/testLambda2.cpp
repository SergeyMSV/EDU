#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace test
{

void UnitTest_Lambda2_Func(int a, std::string s, std::function<void (int)> f)
{
	std::cout << s ;

	f(a);
}

void UnitTest_Lambda2()
{
	std::cout << "UnitTest_Lambda2" << std::endl;

	{
		auto X = [](int a)->void { std::cout << " PREVED: " << a << std::endl; };
		auto Y = [](int a)->void { std::cout << " MEDVED: " << a << std::endl; };

		UnitTest_Lambda2_Func(1, "example X", X);
		UnitTest_Lambda2_Func(2, "example Y", Y);
	}
}

}
