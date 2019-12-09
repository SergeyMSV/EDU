#include <iostream>

namespace Task_7
{

template<std::size_t size>
class A
{
public:
	explicit A() { std::cout << "A " << size << std::endl; }

private:
	A<size - 1> a;
};

template<>
class A<0>
{
public:
	explicit A() { std::cout << "A 0 - first one" << std::endl; }
};

int Main()
{
	A<10> a;

	return 0;
}

}