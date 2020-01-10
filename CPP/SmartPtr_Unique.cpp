#include "SmartPtr_Unique.h"

#include <iostream>

namespace test
{
	namespace test_smart_ptr_unique
	{

class tClass
{
	int m_ID;

public:
	tClass(int a, int b, int c)
	{
		static int Index = 0;

		m_ID = ++Index;

		std::cout << "c_tor: " << m_ID << std::endl;
	}

	~tClass()
	{
		std::cout << "d_tor: " << m_ID << std::endl;
	}

	void DoSomething()
	{
		std::cout << "DoSomething: " << m_ID << std::endl;
	}
};

class tClass2
{
	smart_ptr::tUniquePtr<tClass> m_A;
public:
	tClass2(int a, int b, int c)
	{
		m_A = smart_ptr::Make_UniquePtr<tClass>(a, b, c);

		throw 10;
	}
};

	}

void UnitTest_SmartPtr_Unique()
{
	std::cout << "UnitTest_SmartPtr_Unique" << std::endl;

	using namespace smart_ptr;
	using namespace test_smart_ptr_unique;

	{
		tUniquePtr<tClass> SPtr(new tClass(1, 2, 3));
	}

	std::cout << "---------------------" << std::endl;

	{
		tUniquePtr<tClass> SPtr1(new tClass(1, 2, 3));

		tUniquePtr<tClass> SPtr2 = std::move(SPtr1);

		//SPtr1.Get()->DoSomething();
		SPtr2.Get()->DoSomething();
	}

	std::cout << "---------------------" << std::endl;

	{
		tUniquePtr<tClass> SPtr = Make_UniquePtr<tClass>(1, 2, 3);
	}

	std::cout << "---------------------" << std::endl;

	{
		try
		{
			tClass2 A(1, 2, 3);
		}
		catch (int ex)
		{
			std::cout << "Exception: " << ex << std::endl;
		}
	}
}

}
