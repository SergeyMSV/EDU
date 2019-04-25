#include "testClass2.h"

#include <iostream>

namespace test
{

void UnitTest_Class2()
{
	std::cout << "UnitTest_Class2" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//appropriate constructor is explicit

	//tClass_2 Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	//Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	tClass_2 Class1(4);//OK

	Class1 = tClass_2(4);//OK
	//////////////////////////////////////////////////////////////////////////////////////////////////
}

}
