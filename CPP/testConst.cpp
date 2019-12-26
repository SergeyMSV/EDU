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
		//� ������� �� ������ �� ������������� ��������, ������� ����� ���� ���������������� ������ �������������� l-values, ������ �� ����������� �������� ����� ���� ���������������� �������������� l-values, ������������ l-values � r-values.
		
		int a = 7;
		const int& ref1 = a; // ������, a - ��� ������������� l-value

		const int b = 9;
		const int& ref2 = b; // ������, b - ��� ����������� l-value

		const int& ref3 = 5; // ������, 5 - ��� r-value

		//int& ref4 = 6;//ER: initial reference to non-const must be an l-value

		//const int c = 7;
		//int& ref5 = c;//ER: qualifier dropped in binding reference of type "int&" to initializer of type "const int"

		int& ref6 = a;
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

	{
		gDate2.GetMonth();//������ ��������� ��� ����������� ��������

		tDate Date(4, 5, 6);

		//auto Month = Date.GetMonth();//������ ��������� ��� ������������� ��������
		//����� ����� int Month (��� ������, �.�. auto ������ �������� �� ����� �� ������)

		int& Month = Date.GetMonth();//������ ��������� ��� ������������� ��������

		Month++;

		std::cout << "Month: " << Month << std::endl;
	}

	{
		int& A = GetFigure();//IT IS NOT CORRECT ACTUALLY

		std::cout << A << std::endl;
	}
}

}