#include <iostream>

namespace Task_4
{

class A
{
public:
	int& value() { return m_value; }

private:
	int m_value = 0;//!!!
};

int Main()
{
	A a;

	auto closure = [&] { return a.value(); };
	//Здесь не возвращается ссылочный тип
	//следовательно происходит копирование
	auto value = closure();
	++value;

	std::cout << a.value() << std::endl;

	////////////////////////////////////////////////////////////////////
	int& value2 = a.value();
	++value2;

	//int& closure2 = [&a]() -> int& { return a.value(); };
	//Похоже, lambda работает только с константами, поэтому происходит копирование
	//следовательно происходит копирование
	//auto value3 = closure2();
	//++value3;

	////////////////////////////////////////////////////////////////////
	//auto closure2 = [a] { a; return a.value(); };//doesn't work
	////////////////////////////////////////////////////////////////////
	return 0;
}

}