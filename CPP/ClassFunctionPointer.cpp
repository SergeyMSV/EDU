#include <iostream>

//Alexandrescu, p.137-138

namespace class_function_pointer
{

class tParrot
{
public:
	tParrot() { }

	void Eat()
	{
		std::cout<< "niam, niam, niam...\n";
	}

	void Speak()
	{
		std::cout << "blah, blah, blah...\n";
	}

	int GetFigure(int a)
	{
		return a + 10;
	}
};

}

void UnitTest_ClassFunctionPointer()
{
	using namespace class_function_pointer;

	std::cout << "UnitTest_ClassFunctionPointer" << std::endl;

	tParrot A;
	tParrot* pA = &A;

	{
		typedef void (tParrot::* TpMemFun)();

		TpMemFun pActivity = &tParrot::Eat;

		(A.*pActivity)();
		(pA->*pActivity)();

		pActivity = &tParrot::Speak;

		(A.*pActivity)();
		(pA->*pActivity)();
	}

	{//That's not fact that this works with other compilers... (it might be fair for old compilers... the book is rather outdated)
		typedef int (tParrot::* TpMemFun)(int);

		TpMemFun pActivity = &tParrot::GetFigure;

		int Res = (A.*pActivity)(45);
		Res = (pA->*pActivity)(33);

		Res += 0;//just a statement for a breakpoint
	}

}
