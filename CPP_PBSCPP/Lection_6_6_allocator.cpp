#include <iostream>

#include <string>

namespace lection_6_6
{
/*
class tClassA
{
	int param;

public:
	tClassA(int a) : param(a)
	{
		std::cout << "tClassA::tClassA(" << a << ")" << std::endl;
	}

	virtual ~tClassA()
	{
		std::cout << "tClassA::~tClassA()" << std::endl;
	}

	static void* operator new(size_t sz)
	{
		std::cout << "tClassA::operator new" << std::endl;

		return ::operator new(sz);
	}

	static void operator delete(void* ptr)
	{
		std::cout << "tClassA::operator delete" << std::endl;

		::operator delete(ptr);
	}
};
*/
}

int main_lection_6_6()
{
	using namespace lection_6_6;

	{
		/*tClassA* A = new tClassA(4);

		delete A;*/
	}

	std::cout << "main_lection_6_6.end" << std::endl;

	return 0;
}