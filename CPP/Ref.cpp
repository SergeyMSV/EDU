#include "Ref.h"

#include <iostream>

namespace test
{

void UnitTest_Ref()
{
	std::cout << "UnitTest_Ref" << std::endl;

	{
		//� C++11 �������� ����� ��� ������ � ������ r-value.
		//������ r-value � ��� ������, ������� ���������������� ������ ���������� r-values.
		//���� ������ l-value ��������� � �������������� ������ ����������, ������ r-value 
		//��������� � �������������� �������� ����������:
		int x = 7;
		int& lref = x; // ������������� ������ l-value ���������� x (�������� l-value)
		int&& rref = 7; // ������������� ������ r-value ��������� 7 (�������� r-value)

		rref = 5;

		rref = x;//�����-�� �������� ������� ��������������...!!! ��� ��������� x - rref

		//int y;
		//rref = y;//ER: using uninitialized memory "y"

		//int&& rref2 = x;//ER: rvalue reference cannot be bound to an lvalue
		//const int&& rref3 = x;//ER: rvalue reference cannot be bound to an lvalue

		std::cout << lref << " " << rref << std::endl;

		//������ r-value ����� ��� �������� ��������:
		//
		// 1. ��� ����������� ����������������� ����� �������, ������� ����������������,
		//    �� ����������������� ����� ������ r-value (������ l-value �� ����������� �������
		//    ����� ����� ��� ������).
		//
		// 2. ������������� ������ r-value ��������� ��� �������� �������� r-values,
		//    �� ������� ��������� ������ r-value!
	}

	{
		Fraction&& rref = Fraction(4, 7); // ������ r-value �� ��������� ������ ������ Fraction

		std::cout << rref << '\n';

		//����������� ��������� ������ Fraction(4, 7) ������ ����� �� �� ������� ���������
		//� ����� ���������, � ������� �� ���������.������, ��� ��� �� ��������������
		//������ r-value ���� ��������� ��������, �� ��� ����������������� �����
		//������������� �� ����������������� ����� ����� ������ r-value, �.�. �� �����
		//�����.
		//����� �� ���������� ������ r-value ��� ������ �������� ���������� �������
		//������ Fraction.

	}// rref (� ��������� ������ ������ Fraction) ������� �� ������� ��������� �����

	{
		int&& rref = 7; // ��������� �� �������������� ������ r-value ��������� 7, �� ��������� ��������� ������ �� ��������� 7, �� ������� ��������� ������ r-value

		rref = 12;

		std::cout << rref;

		//���� ��� ����� ���������� ��������, �� ��� ������������� ������ r-value ���������,
		//��������� ��������� ������, �� ������� ��������� ������ r-value (��� �� ��������� �� ��� �������).

		//������ r-value �� ����� ����� ������������ ���, ��� ��� ������������ � �������� ����.
	}

	{
		const int& ref4 = 7; // D
	}
}

}

//������� ������ r-value

//�� ����� ������� �� ������ ���������� ������ r-value �� ������� �� ��� �� �������,
//�� ������� �� ����� ������� �� ������ ���������� ������ l-value �� �������.
//� ����������� ������� �� ������ ���������� ������� ������(����������� �� ���������
//������), � ������, �� ������� ����� ��������� ������ � ������ �� ������� ���������
//� ����� �������.