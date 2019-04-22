#include <iostream>

#include <vector>

namespace test
{

void UnitTest_Class();
void UnitTest_Class2();
void UnitTest_Exception();
void UnitTest_Lambda();
void UnitTest_Lambda2();
void UnitTest_Mutex();
void UnitTest_Pointer();
void UnitTest_Struct();
void UnitTest_Thread();
void UnitTest_Type();

}

int main()
{
	test::UnitTest_Class();
	test::UnitTest_Class2();
	test::UnitTest_Exception();
	test::UnitTest_Lambda();
	test::UnitTest_Lambda2();
	test::UnitTest_Mutex();
	test::UnitTest_Pointer();
	test::UnitTest_Struct();
	test::UnitTest_Thread();
	test::UnitTest_Type();

    std::cout << "Hello World!\n";

	{
		int A = 0;

		std::vector<int*> Vector(10, &A);

		std::fill(Vector.begin(), Vector.end(), nullptr);
	}
	
	{
		int A = 1'000'000;
		float B = 0.000'000'015;
		auto C = 0b0000'1010'0011'1110;//that is int, it can't be bool

		auto A1 = 1'000'000;
		auto B1 = 0.000'000'015;
		auto C1 = 0b0000'1010'0011'1110;
		auto D1 = 0xABCD'1234;
		auto E1 = 1'2'3'4'000'1;
	}

	return 0;
}
