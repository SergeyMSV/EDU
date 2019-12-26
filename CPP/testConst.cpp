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
		//� ������� �� ������ �� ������������� ��������, ������� ����� ���� ���������������� ������ �������������� l - values, ������ �� ����������� �������� ����� ���� ���������������� �������������� l - values, ������������ l - values � r - values.
		
		int a = 7;
		const int& ref1 = a; // ������, a - ��� ������������� l-value

		const int b = 9;
		const int& ref2 = b; // ������, b - ��� ����������� l-value

		const int& ref3 = 5; // ������, 5 - ��� r-value
	}

	{
		//��� ������� � �������� ����� ����������� ������, ��� �������� �������������
		//��������� const, ���� ���� �������� ���������� ������� �� ��������:

		int value = 7;
		const int& ref = value; // ������� ����������� ������ �� ���������� value
		int& ref2 = value;//[srg]

		value = 8; // ������, value - ��� �� ���������
	//	ref = 9; // ������, ref - ��� ���������
		ref2 = 10;//[srg]

		std::cout << "Century: " << tDate::Century << std::endl;
	}
}

}