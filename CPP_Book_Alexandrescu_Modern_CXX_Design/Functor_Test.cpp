#include "Functor.h"

#include <iostream>

void DoSomething()
{
	std::cout << "DoSomething ()\n";
}

void DoSomething1(int)
{
	std::cout << "DoSomething 1 ()\n";
}

namespace TL
{

void UnitTest_Functor2()
{
	class FunctorImplA : public FunctorImpl<double, TYPELIST_2(int, double)>
	{
	public:
		virtual double operator()(int a, double b)
		{
			return a + b;
		}
		//virtual FunctorImpl* Clone() const { return this; };
	};

	FunctorImplA FA;

	Functor<double, TYPELIST_2(int, double)> A(std::auto_ptr<FunctorImpl<double, TYPELIST_2(int, double)>>(FA));

	//IT HASN'T BEEN IMPLEMENTED PROPERLY AND FULLY...

	//A.operator()(2);
	//double Res = A(4, 2.6);
}

}

void UnitTest_Functor()
{
	{
		class tDevice
		{
		public:
			void operator()()
			{
				std::cout << "tDevice ()\n";
			}

			void operator()(int)
			{
				std::cout << "tDevice 2 ()\n";
			}
		}LA;

		Functor<tDevice*> A(&LA);

		(*A.Get())();
		(*A.Get())(24);
	

		void(*PFunc)() = &DoSomething;

		Functor<void(*)()> B(PFunc);

		(*B.Get())();

		void(*PFunc2)(int) = &DoSomething1;

		Functor<void(*)(int)> C(PFunc2);

		(*C.Get())(24);
	}

	TL::UnitTest_Functor2();
}
