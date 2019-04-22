#include <iostream>

namespace Task_11
{

class A
{
public:
	//inline static int a = 10;//ER: inline для функций...

	//***все функции определённые в теле класса по умполчанию inline

	const static int a = 10;//[srg]
};

int Main()
{
	A a;

	std::cout << a.a << std::endl;

	return 0;
}

}