#include "testClass3.h"

#include <iostream>

namespace test
{

tClass_3<int> MakeClass_3(int value)
{
	return tClass_3<int>(new int(value));
}

void UnitTest_Class3()
{
	std::cout << "UnitTest_Class3" << std::endl;

	{
		tClass_3<int> A;

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

		tClass_3<int> A(PtrA);

		//delete PtrA;//EXCEPTION

		std::cout << "A" << std::endl;
	}

	{
		tClass_3<int> A(new int(4));

		tClass_3<int> B(new int(5));

		tClass_3<int> C(new int(6));

		C = B;//copy c_tor
	
		C = MakeClass_3(8);//move
		// онструктор перемещени€ и оператор присваивани€ перемещением вызываютс€, когда 
		//аргументом дл€ создани€ или присваивани€ €вл€етс€ r - value.
		//„аще всего этим r - value будет литерал или временное значение (временный объект).

		std::cout << "A" << std::endl;
	}
}

}