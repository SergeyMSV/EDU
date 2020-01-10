#include <iostream>

namespace class_explicit
{

class tClass
{
	int A;

public:
	tClass()
	{
		A = 0;
	}

	explicit tClass(int a)
	{
		A = a;
	}

	tClass(const tClass& value)
	{

	}
};

}

void UnitTest_ClassExplicit()
{
	using namespace class_explicit;

	std::cout << "UnitTest_ClassExplicit" << std::endl;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//appropriate constructor is explicit

	//tClass_2 Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	//Class1 = 4;//ER: no suitable constructor exists to convert from "int" to "Class2"

	tClass Class1(4);//OK

	Class1 = tClass(4);//OK
	//////////////////////////////////////////////////////////////////////////////////////////////////
}

