#include <iostream>

namespace Task_8
{

class A
{
public:
	explicit A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
	A(const A&) { std::cout << "A copy constructor" << std::endl; }
	A(A&&) { std::cout << "A move constructor" << std::endl; }
};

class B : public A
{
public:
	explicit B() { std::cout << "B constructor" << std::endl; }
	~B() { std::cout << "B destructor" << std::endl; }
	B(const B&) { std::cout << "B copy constructor" << std::endl; }
	B(B&&) { std::cout << "B move constructor" << std::endl; }
};

int Main()
{
	B b1;

	std::cout << "------------------" << std::endl;

	B b2 = b1;

	std::cout << "------------------" << std::endl;

	B b3 = std::move(b2);

	return 0;
}

}