#pragma once

#include <iostream>

namespace test
{

class tClass_Static_1
{
public:
	//**видимо, это что-то вроде прототипа... похоже...
	static int X;//объ€вл€ем статическую переменную-член (нужно ещЄ определить, см. .cpp)
	//принадлежит классу, как таковому, можно вызывать без создани€ объекта
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