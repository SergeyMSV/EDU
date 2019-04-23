#pragma once

namespace test
{

int gX;

const int gXConst = 10;

const int gValue1 = 6;//копирующая инициализация
const int gValue2(8);//прямая инициализация
const int gValue3{ 11 };//uniform инициализация (C++11)

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
	//Оказывается, константные объекты класса могут явно вызывать только 
	//константные методы класса, а getValue() не указан как константный метод.
	//Константный метод – это метод, который гарантирует, что не будет изменять 
	//объект или вызывать неконстантные методы класса(поскольку они могут изменить 
	//объект).
	//auto GetYear() { return m_Year; }
	auto GetYear() const { return m_Year; }

	auto GetDay() const { int a = m_Day + 34; return m_Day; }
	//auto GetDay() const { return ++m_Day; }//так нельзя

	static const int Century = 21;
};
//Как только константный объект класса инициализируется через конструктор,
//любая попытка изменить переменные-члены объекта запрещена.
const tDate gDate1;
const tDate gDate2(1, 2, 3);
const tDate gDate3{ 1, 2, 3 };

}