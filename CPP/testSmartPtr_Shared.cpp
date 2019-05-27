#include "testSmartPtr_Shared.h"

#include <iostream>

namespace test
{
	namespace test_smart_ptr_shared
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

	}

void UnitTest_SmartPtr_Shared()
{
	std::cout << "UnitTest_SmartPtr_Shared" << std::endl;

	using namespace smart_ptr;
	using namespace test_smart_ptr_shared;

	{
		tSharedPtr<tClass> SPtr(new tClass(1, 2, 3));
	}

	std::cout << "---------------------" << std::endl;

	{
		tSharedPtr<tClass> SPtr1(new tClass(1, 2, 3));

		tSharedPtr<tClass> SPtr2 = SPtr1;

		SPtr1.Get()->DoSomething();
		SPtr2.Get()->DoSomething();
	}

	std::cout << "---------------------" << std::endl;

	{
		tSharedPtr<tClass> SPtr1(new tClass(1, 2, 3));

		tSharedPtr<tClass> SPtr2(new tClass(5, 6, 7));

		SPtr2 = SPtr1;

		SPtr1.Get()->DoSomething();
		SPtr2.Get()->DoSomething();
	}

	std::cout << "---------------------" << std::endl;

	{
		tSharedPtr<tClass> SPtr = Make_SharedPtr<tClass>(1, 2, 3);
	}
}

}
