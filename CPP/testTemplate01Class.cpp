#include "testTemplate01Class.h"

namespace test
{

void UnitTest_Template01Class()
{
	std::cout << "UnitTest_Template01Class" << std::endl;

	using namespace Template01;

	tWidget<int> A;
	A.Fun();

	tWidget<char> B;
	B.Fun();

	tWidget<float> C;
	C.Fun();
}

}