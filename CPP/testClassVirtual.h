#pragma once

#include <iostream>

namespace test
{
	namespace class_virtual
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
};

class tClassC : public tClassB
{
public:
	virtual void foo1() { std::cout << "tClassC::foo1" << '\n'; }
	virtual void foo2() { std::cout << "tClassC::foo2" << '\n'; }
	virtual void foo3() { std::cout << "tClassC::foo3" << '\n'; tClassB::foo3(); }
};

	}
}