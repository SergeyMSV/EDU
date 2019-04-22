#include <iostream>

namespace Task_2
{

class A
{
	//virtual void foo() { }
};

class B : public A
{
	//virtual void foo() { }
};

int Main()
{
	auto SizeA = sizeof(A);
	auto SizeB = sizeof(B);

	A* a = new B();

	A* a2 = dynamic_cast<A*>(a);

	//The dynamic_cast operator is intended to be the most heavily used RTTI component.
	//It doesn't give us what type of object a pointer points to. Instead, 
	//it answers the question of whether we can safely assign the address of an object to a pointer of a particular type.

	//If class A doesn't contain virtual function that results in following error.
	//ER: the operand of a runtime dynamic_cast must have a polimorphic class type
	//B* b = dynamic_cast<B*>(a);

	//std::cout << (b != nullptr) << std::endl;

	return 0;
}

}