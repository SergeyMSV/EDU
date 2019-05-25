#include <iostream>

#include <string>

namespace lection_6_1
{

class tClassA
{
	int* m_Array;

public:
	tClassA()
	{
		m_Array = 0;

		std::cout << "tClassA::c_tor_1" << std::endl;
	}

	explicit tClassA(const int capacity)
	{
		m_Array = new int[capacity];

		std::cout << "tClassA::c_tor_2" << std::endl;
	}

	~tClassA()
	{
		delete[] m_Array;

		std::cout << "tClassA::d_tor" << std::endl;
	}
};

class tClassA1
{
	int m_Array[10000];

public:
	tClassA1()
	{
		std::cout << "tClassA1::c_tor_1" << std::endl;
	}

	~tClassA1()
	{
		std::cout << "tClassA1::d_tor" << std::endl;
	}
};

class tClassB
{
	tClassA* m_ClassA;

	tClassA1 m_ClassA1;

public:
	tClassB()
	{
		tClassA A;

		m_ClassA = new tClassA(100000000);

		std::cout << "tClassB::c_tor 1" << std::endl;

		throw std::string("PREVED");

		std::cout << "tClassB::c_tor 2" << std::endl;
	}

	~tClassB()
	{
		delete m_ClassA;

		std::cout << "tClassB::d_tor" << std::endl;
	}
};

}

int main_lection_6_1()
{
	using namespace lection_6_1;

	try
	{
		tClassB B;
	}
	catch (std::string ex)
	{
		std::cout << ex << std::endl;
	}

	return 0;
}