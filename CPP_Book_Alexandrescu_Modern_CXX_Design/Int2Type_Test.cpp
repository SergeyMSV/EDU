#include "Int2Type.h"

#include <iostream>

typedef Int2Type<15> tInt15;

template <bool v>
struct Bool2Type
{
	enum { value = v };
};

typedef Bool2Type<true> tBoolTrue;
typedef Bool2Type<false> tBoolFalse;

void DoSmth(tBoolTrue, int value)
{
	std::cout << "DoSmth(tBoolTrue, int value)\n";
}

void DoSmth(tBoolFalse, int value)
{
	std::cout << "DoSmth(tBoolFalse, int value)\n";
}

void UnitTest_Int2Type()
{
	{
		tInt15 A;

		//A.value = 4;

		char B[10];
		char C[10];

		std::cout << A.value << "\n";
	}
}
