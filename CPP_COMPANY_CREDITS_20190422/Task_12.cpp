#include <iostream>

namespace Task_12
{

static void foo(int a, int b)//Зачем static
{
	std::cout << a << " " << b << std::endl;
}

int Main()
{
	int i = 0;

	foo(++i, i++);

	std::cout << i << std::endl;

	return 0;
}

}