#include "testConst.h"

#include <iostream>

namespace test
{

void UnitTest_Const()
{
	std::cout << "UnitTest_Const" << std::endl;

	std::cout << gX << " " << gXConst << std::endl;

	auto Value1 = gValue1;

	//gValue1++;

	auto Day = gDate2.m_Day;

	//gDate2.m_Day++;//ER: expression must be a modifieble lvalue

	std::cout << "Year: " << gDate2.GetYear() << std::endl;
	std::cout << "Day:  " << gDate2.GetDay() << std::endl;

	std::cout << "Century: " << tDate::Century << std::endl;

	//tDate::Century++;//ER: expression must be a modifieble lvalue


	{
		//В отличие от ссылок на неконстантные значения, которые могут быть инициализированы только неконстантными l - values, ссылки на константные значения могут быть инициализированы неконстантными l - values, константными l - values и r - values.
		
		int a = 7;
		const int& ref1 = a; // хорошо, a - это неконстантное l-value

		const int b = 9;
		const int& ref2 = b; // хорошо, b - это константное l-value

		const int& ref3 = 5; // хорошо, 5 - это r-value
	}

	{
		//При доступе к значению через константную ссылку, это значение автоматически
		//считается const, даже если исходная переменная таковой не является:

		int value = 7;
		const int& ref = value; // создаем константную ссылку на переменную value
		int& ref2 = value;//[srg]

		value = 8; // хорошо, value - это не константа
	//	ref = 9; // нельзя, ref - это константа
		ref2 = 10;//[srg]

		std::cout << "Century: " << tDate::Century << std::endl;
	}
}

}