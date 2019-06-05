#include "testClassVirtual.h"

#include <iostream>

namespace test
{

using namespace class_virtual;

void UnitTest_ClassVirtual()
{
	std::cout << "UnitTest class_virtual" << std::endl;

	{
		tClassA* A = new tClassA();

		A->foo1();
		A->foo2();

		//tClassA* B = new tClassB();//ER: pure virtual function

		tClassA* C = new tClassC();

		C->foo1();
		C->foo2();

		std::cout << "A" << std::endl;
	}

	{
		tClassB* C = new tClassC();

		C->foo1();
		C->foo2();
		C->foo3();
		C->foo4();

		std::cout << "B" << std::endl;
	}
}

}