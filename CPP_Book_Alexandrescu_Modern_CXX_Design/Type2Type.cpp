namespace Type2Type
{

template <typename T>
struct Type2Type
{
	typedef T OriginalType;
};

template <class T, class U>
T* Create(const U& arg, Type2Type<T>)
{
	return new T(arg);
}

void UnitTest()
{
	char* pStr = Create('s', Type2Type<char>());
	int* pInt32 = Create(0x13243546, Type2Type<int>());
}

}