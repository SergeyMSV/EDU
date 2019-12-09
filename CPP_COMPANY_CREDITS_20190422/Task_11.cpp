#include <iostream>

namespace Task_11
{

class A
{
public:
	//inline static int a = 10;//ER: inline для функций...

	//***все функции определённые в теле класса по умполчанию inline

	static const int a = 10;//[srg]
	const int b = 11;//[srg]

	static int c;//[srg]

	int GetB() { return b; }
};

int A::c = 123;

int Main()
{
	A a;

	std::cout << a.a << std::endl;
	std::cout << a.b << std::endl;//[srg]
	std::cout << A::a << std::endl;//[srg]
	//std::cout << A::b << std::endl;//[srg]
	std::cout << a.GetB() << std::endl;//[srg]

	//a.a++;//[srg]
	//a.b++;//[srg]

	//int A::c = 123;//ER: 'c' cannot be defined in the current scope

	A::c++;

	return 0;
}

}