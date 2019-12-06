#include <iostream>

namespace Convert
{

template <class T, class U>
class tConvertion
{
	typedef char tSmall;
	class tBig { char dummy[2]; };
	static tSmall Test(const U&);
	static tBig Test(...);
	static T MakeT();

public:
	enum { exists = sizeof(Test(MakeT())) == sizeof(tSmall) };
	enum { sameType = false };
};

template <class T>
class tConvertion<T, T>
{
public:
	enum { exists = true };
	enum { sameType = true };
};

void UnitTest()
{
	std::cout << tConvertion<int, int>::exists << ' ' << tConvertion<int, int>::sameType << '\n';
	std::cout << tConvertion<double, int>::exists << ' ' << tConvertion<double, int>::sameType << '\n';
	std::cout << tConvertion<float, int>::exists << '\n';
	std::cout << tConvertion<char, int>::exists << '\n';
	
	std::cout << tConvertion<char, char*>::exists << '\n';
}

}