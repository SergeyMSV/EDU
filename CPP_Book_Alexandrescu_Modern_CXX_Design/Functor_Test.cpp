#include "Functor.h"

#include <iostream>

void DoSomething()
{
	std::cout << "DoSomething ()\n";
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
		}LA;

		Functor<tDevice*> A(&LA);

		(*A.Get())();


		void(*PFunc)() = &DoSomething;

		Functor<decltype(PFunc)> B(PFunc);

		(*B.Get())();
	}

	TL::UnitTest_Functor2();
}
