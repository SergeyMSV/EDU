#include "testClassExplicit.h"

#include <iostream>

namespace test
{

using namespace class_explicit;

void UnitTest_ClassExplicit()
{
	std::cout << "UnitTest_ClassExplicit" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//appropriate constructor is explicit

	//tClass_2 Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	//Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	tClass Class1(4);//OK

	Class1 = tClass(4);//OK
	//////////////////////////////////////////////////////////////////////////////////////////////////
}

}
