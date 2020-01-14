#include <iostream>

struct tGuard
{
	tGuard()
	{
		std::cout << "tGuard-c_tor\n";
	}

	~tGuard()
	{
		std::cout << "tGuard-d_tor\n";
	}
};

struct tValue
{
	int i = 0;

	tValue()
	{
		std::cout << "tValue c_tor: default\n";
	}

	tValue(const tValue& val)
	{
		i = 2;//it's possible to see it in the caller

		std::cout << "tValue c_tor: copy\n";
	}

	~tValue()
	{
		std::cout << "tValue d_tor\n";
	}

	tValue& operator=(const tValue& val)
	{
		std::cout << "tValue operator=\n";
	}
};

class tDataSet
{
	tValue m_Val;

public:
	tValue GetVal()
	{
		tGuard Mtx;

		return m_Val;
		//1. m_Val is copied into the caller
		//2. d_tors are called
	}
};

void UnitTest_ReturnToCallerAndDestructor()
{
	tDataSet A;

	tValue Val = A.GetVal();

	std::cout << "The end :)\n";
}