#include <iostream>

#include <string>

namespace Task_5
{

void foo(std::string& str)
{
	std::cout << str.append(", world!") << std::endl;
}

//����� ����������� ������ ���������������� ��������� r-value,
//����� ����� r-value ������������ � ������������ �� �������� ����� ������.
void foo1(const std::string& str)//compatible with C++98
{
	std::cout << str + ", world! - foo1" << std::endl;
}// � ����� ����� r-value ������������ �� ���� �����, ����� ���� ����������� ������ ������������

void foo2(std::string&& str)
{
	std::cout << str.append(", world! - foo2") << std::endl;
}

int Main()
{
	//foo(std::string("Hello"));//ER: initial value of reference to non-const must be an lvalue

	////////////////////////////////////////////////////////////////////
	foo1(std::string("Hello"));//���������, ��� r-value

	foo2(std::string("Hello"));//���������, ��� r-value
	////////////////////////////////////////////////////////////////////

	return 0;
}

}