#pragma once

#include <iostream>

namespace test
{

class tClass_Static_1
{
public:
	//**������, ��� ���-�� ����� ���������... ������...
	static int X;//��������� ����������� ����������-���� (����� ��� ����������, ��. .cpp)
};

//void Foo()//Linker error: already defined
//{
//	std::cout << "Foo" << std::endl;
//}

static void FooStatic()
{
	std::cout << "FooStatic" << std::endl;
}

}