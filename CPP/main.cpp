#include <iostream>

#include <map>
#include <vector>
#include <utility>

namespace test
{

void UnitTest_Lambda();
void UnitTest_Class();
void UnitTest_Struct();
void UnitTest_Type();

}

int main()
{
	test::UnitTest_Lambda();
	test::UnitTest_Class();
	test::UnitTest_Struct();
	test::UnitTest_Type();

    std::cout << "Hello World!\n";

	{
		int A = 0;

		std::vector<int*> Vector(10, &A);

		std::fill(Vector.begin(), Vector.end(), nullptr);
	}

}
