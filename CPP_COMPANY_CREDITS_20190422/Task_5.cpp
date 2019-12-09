#include <iostream>

#include <string>

namespace Task_5
{

void foo(std::string& str)
{
	std::cout << str.append(", world!") << std::endl;
}

//Когда константная ссылка инициализируется значением r-value,
//время жизни r-value продлевается в соответствии со временем жизни ссылки.
void foo1(const std::string& str)//compatible with C++98
{
	std::cout << str + ", world! - foo1" << std::endl;
}// и время жизни r-value продлевается до этой точки, когда сама константная ссылка уничтожается

void foo2(std::string&& str)
{
	std::cout << str.append(", world! - foo2") << std::endl;
}

int Main()
{
	//foo(std::string("Hello"));//ER: initial value of reference to non-const must be an lvalue

	////////////////////////////////////////////////////////////////////
	foo1(std::string("Hello"));//передаётся, как r-value

	foo2(std::string("Hello"));//передаётся, как r-value
	////////////////////////////////////////////////////////////////////

	return 0;
}

}