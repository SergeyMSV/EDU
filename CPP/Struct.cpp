#include <string>

#include <iostream>

struct tStruct
{
	int A;

	std::string B;

	double C;
};

void UnitTest_Struct()
{
	std::cout << "UnitTest_Struct" << std::endl;

	tStruct Struct{ 4, "four" };

	tStruct Struct2{ 5, "five", 3.4 };

	std::cout << Struct.A << " " << Struct.B << std::endl;
}
