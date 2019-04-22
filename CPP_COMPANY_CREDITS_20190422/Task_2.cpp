#include <iostream>

namespace Task_2
{

class A
{
	virtual void foo() { }
};

class B : public A
{
	//virtual void foo() { }
};

int Main()
{
	//Empty class size = 1 byte
	//Class containing __vfptr, size = 8 byte

	auto SizeA = sizeof(A);
	auto SizeB = sizeof(B);

	//////////////////////////////////////////////////////////////

	A* a = new B();

	//The dynamic_cast operator is intended to be the most heavily used RTTI component.
	//It doesn't give us what type of object a pointer points to. Instead, 
	//it answers the question of whether we can safely assign the address of an object to a pointer of a particular type.

	//If class A doesn't contain virtual function that results in following error.
	//ER: the operand of a runtime dynamic_cast must have a polimorphic class type
	B* b = dynamic_cast<B*>(a);

	std::cout << (b != nullptr) << std::endl;

	////////////////////////////////////////////////////////////////////
	{
		A* a2 = dynamic_cast<A*>(a);

		A* c = new A();

		B* d = dynamic_cast<B*>(c);

		std::cout << (d != nullptr) << std::endl;
	}
	////////////////////////////////////////////////////////////////////
	{
		double A = 3.14;

		int B = static_cast<int>(A);

		std::cout << B << std::endl;
	}
	////////////////////////////////////////////////////////////////////

	return 0;
}

}