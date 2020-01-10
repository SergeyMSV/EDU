#include <iostream>

#include <memory>

void DoSomething()
{
	std::cout << "DoSomething ()\n";
}

int DoSomething(int a)
{
	std::cout << "DoSomething(int)\n";

	return a + 10;
}

void UnitTest_FunctionPointer()
{
	std::cout << "UnitTest_FunctionPointer" << std::endl;

	{
		void(*PFun)() = &DoSomething;

		(*PFun)();
	}

	{
		int(*PFun)(int) = &DoSomething;

		int Res = (*PFun)(4);

		Res += 0;//Just a statement
	}

	{
		typedef int(*TPFunc)(int);

		TPFunc PFun = &DoSomething;

		int Res = (*PFun)(4);

		Res += 0;//Just a statement
	}
}
