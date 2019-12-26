#pragma once

namespace test
{

int gX;

const int gXConst = 10;

const int gValue1 = 6;//���������� �������������
const int gValue2(8);//������ �������������
const int gValue3{ 11 };//uniform ������������� (C++11)

class tDate
{
public:
	int m_Year;
	int m_Month;
	int m_Day;

public:
	tDate() = default;

	tDate(int year, int month, int day)
	{
		m_Year = year;
		m_Month = month;
		m_Day = day;
	}
	//�����������, ����������� ������� ������ ����� ���� �������� ������ 
	//����������� ������ ������, � getValue() �� ������ ��� ����������� �����.
	//����������� ����� � ��� �����, ������� �����������, ��� �� ����� �������� 
	//������ ��� �������� ������������� ������ ������(��������� ��� ����� �������� 
	//������).
	//auto GetYear() { return m_Year; }
	auto GetYear() const { return m_Year; }

	auto GetDay() const { int a = m_Day + 34; return m_Day; }
	//auto GetDay() const { return ++m_Day; }//��� ������

	static const int Century = 21;
};
//��� ������ ����������� ������ ������ ���������������� ����� �����������,
//����� ������� �������� ����������-����� ������� ���������.
const tDate gDate1;
const tDate gDate2(1, 2, 3);
const tDate gDate3{ 1, 2, 3 };

}