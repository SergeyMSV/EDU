#include "testClassMove.h"

#include <iostream>

namespace test
{

using namespace class_move;

tClass<int> MakeClass(int value)
{
	return tClass<int>(new int(value));
}

void UnitTest_ClassMove()
{
	std::cout << "UnitTest class_move::tClass" << std::endl;

	{
		tClass<int> A;

		std::cout << "A" << std::endl;
	}

	{
		int* PtrA = new int(4);

		//tClass_3<int> A(PtrA);

		delete PtrA;//OK

		std::cout << "A" << std::endl;
	}

	{
		int* PtrA = new int(4);

		tClass<int> A(PtrA);

		//delete PtrA;//EXCEPTION

		std::cout << "A" << std::endl;
	}

	{
		tClass<int> A(new int(4));

		tClass<int> B(new int(5));

		tClass<int> C(new int(6));

		C = B;//copy c_tor
	
		C = MakeClass(8);//move
		// онструктор перемещени€ и оператор присваивани€ перемещением вызываютс€, когда 
		//аргументом дл€ создани€ или присваивани€ €вл€етс€ r - value.
		//„аще всего этим r - value будет литерал или временное значение (временный объект).

		std::cout << "A" << std::endl;
	}
}

}