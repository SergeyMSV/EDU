#include "testConst.h"

#include <iostream>

namespace test
{

int& GetFigure()
{
	int A = 45;

	return A;//W: returning address of local variable or temporary: A
}

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

	//int RR = tDate::RR;//ER: a nonstatic reference must be relative to a specific object
	int RR = gDate2.RR;

	{
		//В отличие от ссылок на неконстантные значения, которые могут быть инициализированы только неконстантными l-values, ссылки на константные значения могут быть инициализированы неконстантными l-values, константными l-values и r-values.
		
		int a = 7;
		const int& ref1 = a; // хорошо, a - это неконстантное l-value

		const int b = 9;
		const int& ref2 = b; // хорошо, b - это константное l-value

		const int& ref3 = 5; // хорошо, 5 - это r-value

		//int& ref4 = 6;//ER: initial reference to non-const must be an l-value

		//const int c = 7;
		//int& ref5 = c;//ER: qualifier dropped in binding reference of type "int&" to initializer of type "const int"

		int& ref6 = a;
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

	{
		gDate2.GetMonth();//вызван экземпляр для константных объектов

		tDate Date(4, 5, 6);

		//auto Month = Date.GetMonth();//вызван экземпляр для неконстантных объектов
		//здесь будет int Month (без ссылки, т.к. auto просто копирует не глядя на ссылки)

		int& Month = Date.GetMonth();//вызван экземпляр для неконстантных объектов

		Month++;

		std::cout << "Month: " << Month << std::endl;
	}

	{
		int& A = GetFigure();//IT IS NOT CORRECT ACTUALLY

		std::cout << A << std::endl;
	}
}

}