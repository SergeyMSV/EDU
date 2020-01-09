#include "Type2Type.h"

template <class T, class U>
T* Create(const U& arg, Type2Type<T>)
{
	return new T(arg);
}

void UnitTest_Type2Type()
{
	char* pStr = Create('s', Type2Type<char>());
	int* pInt32 = Create(0x13243546, Type2Type<int>());
}
