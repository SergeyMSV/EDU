#include <iostream>

namespace Task_6
{

class A
{
public:
	void foo(int value) { std::cout << "A value: " << value << std::endl; }
	void foo() { std::cout << "A foo " << std::endl; }//[srg]
};

class B :public A
{
public:
	//����� �������� ��������� �������, �������� �� ��, ��� ���������� ���������� ������,
	//������� ������ ���������� ��� ������� ���� �������.
	void foo() { std::cout << "B foo" << std::endl; }
};

int Main()
{
	B b;
	//b.foo(100);//���������, ���� ������ ������� �� B
	b.foo();

	return 0;
}

}