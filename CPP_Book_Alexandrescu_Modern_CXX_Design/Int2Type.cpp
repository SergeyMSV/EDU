#include <iostream>

namespace Int2Type
{

template <int v>
struct tInt2Type
{
	enum { value = v };
};

typedef tInt2Type<15> tInt15;

template <bool v>
struct tBool2Type
{
	enum { value = v };
};

typedef tBool2Type<true> tBoolTrue;
typedef tBool2Type<false> tBoolFalse;

void DoSmth(tBoolTrue, int value)
{
	std::cout << "DoSmth(tBoolTrue, int value)\n";
}

void DoSmth(tBoolFalse, int value)
{
	std::cout << "DoSmth(tBoolFalse, int value)\n";
}

void UnitTest()
{
	{
		tInt15 A;

		//A.value = 4;

		char B[10];
		char C[10];

		std::cout << A.value << "\n";
	}
}

}