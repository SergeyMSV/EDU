#include <iostream>

namespace Task_1
{

class A
{
public:
	virtual void foo() { std::cout << "A foo" << std::endl; }

	virtual void foo1() const { std::cout << "A foo1" << std::endl; }
};

class B :public A
{
public:
	virtual void foo() const { std::cout << "B foo" << std::endl; }

	virtual void foo1() const { std::cout << "B foo1" << std::endl; }
};

int Main_1()
{
	const A* a = new B();
	//a->foo();//ER: the object has type qualifiers that are not compatible with the member function "A::foo" object type is "const A"
	a->foo1();

	delete a;
	return 0;
}

int Main_2()
{
	A* a = new B();
	a->foo();//A::foo() >>> "A foo"

	delete a;
	return 0;
}

int Main()
{
	Main_1();
	Main_2();

	return 0;
}

}