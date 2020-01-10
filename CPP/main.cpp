#include <iostream>

#include <vector>

namespace test
{

void UnitTest_Const();
void UnitTest_Exception();
void UnitTest_Mutex();
void UnitTest_Ref();
void UnitTest_SmartPtr_Shared();
void UnitTest_SmartPtr_Unique();
void UnitTest_Static1();
void UnitTest_Static2();
void UnitTest_Static3();
void UnitTest_Struct();
void UnitTest_Template01Class();
void UnitTest_Thread();
void UnitTest_Type();

}

void UnitTest_ClassExplicit();
void UnitTest_ClassFunctionOverride();
void UnitTest_ClassFunctionPointer();
void UnitTest_ClassFucnctionVirtual();
void UnitTest_ClassMove();
void UnitTest_FunctionPointer();
void UnitTest_Lambda();
void UnitTest_Lambda2();
void UnitTest_SmartPointer();

int main()
{
	using namespace test;

	UnitTest_ClassExplicit();
	UnitTest_ClassFunctionOverride();
	UnitTest_ClassFunctionPointer();
	UnitTest_ClassFucnctionVirtual();
	UnitTest_ClassMove();
	UnitTest_Const();
	UnitTest_Exception();
	UnitTest_FunctionPointer();
	UnitTest_Lambda();
	UnitTest_Lambda2();
	UnitTest_Mutex();
	UnitTest_Ref();
	UnitTest_SmartPointer();
	UnitTest_SmartPtr_Shared();
	UnitTest_SmartPtr_Unique();
	UnitTest_Static1();
	UnitTest_Static2();
	UnitTest_Static3();
	UnitTest_Struct();*/
	UnitTest_Template01Class();
	/*UnitTest_Thread();
	UnitTest_Type();

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
