#include <iostream>

namespace class_function_virtual
{

class tClassA
{
public:
	virtual void foo1() { std::cout << "tClassA::foo1" << '\n'; }
	virtual void foo2() { std::cout << "tClassA::foo2" << '\n'; }
};

class tClassB : public tClassA
{
public:
	virtual void foo1() { std::cout << "tClassB::foo1" << '\n'; }
	virtual void foo2() { std::cout << "tClassB::foo2" << '\n'; }
	virtual void foo3() = 0
	{
		std::cout << "tClassB::foo3 pure virtual" << '\n';
	}
	virtual void foo4() { std::cout << "tClassB::foo4" << '\n'; }
	virtual void foo5() { std::cout << "tClassB::foo5" << '\n'; }
};

class tClassC : public tClassB
{
public:
	virtual void foo1() { std::cout << "tClassC::foo1" << '\n'; }
	virtual void foo2() { std::cout << "tClassC::foo2" << '\n'; }
	virtual void foo3() { std::cout << "tClassC::foo3" << '\n'; tClassB::foo3(); }

	void foo5() { std::cout << "tClassC::foo5 --- that's actually virtual too... no replacement" << '\n'; }//replacement
};

}

void UnitTest_ClassFucnctionVirtual()
{
	using namespace class_function_virtual;

	std::cout << "UnitTest class_virtual" << std::endl;

	{
		tClassA* A = new tClassA();

		A->foo1();
		A->foo2();

		//tClassA* B = new tClassB();//ER: pure virtual function

		tClassA* C = new tClassC();

		C->foo1();
		C->foo2();

		std::cout << "A" << std::endl;
	}

	{
		tClassB* C = new tClassC();

		C->foo1();
		C->foo2();
		C->foo3();
		C->foo4();
		C->foo5();

		std::cout << "B" << std::endl;
	}
}
