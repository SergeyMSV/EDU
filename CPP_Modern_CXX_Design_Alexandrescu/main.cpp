
class NullType{};
struct EmptyType{};

template<class T, class U>
struct Typelist
{
	typedef T Head;
	typedef U Tail;
};

typedef Typelist<char, Typelist<int, unsigned char>> CharList;

typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;
///////////////////////////////////////////////////////////////////////////////////////////////////
template<class TList> struct Length
{
	enum { value = 0 };//?????
};
template<> struct Length<NullType>
{
	enum { value = 0 };
};
template<class T, class U>
struct Length<Typelist<T, U>>
{
	enum { value = 1 + Length<U>::value };
};
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Typelist<int, char> ee;

	auto Size_CharList = Length<SignedIntegrals>::value;

	//CharList e1;

	//SignedIntegrals qw;

	return 0;
}