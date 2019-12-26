#include "mConvertion.h"

#include <iostream>

namespace Convert
{

void UnitTest()
{
	class tSuper { };
	class tSuperSub :public tSuper { };

	class tJustAClass { };

	std::cout << (SUPERSUBCLASS(tSuper, tSuperSub) ? "Yes" : "No") << '\n';
	std::cout << (SUPERSUBCLASS(tSuperSub, tSuper) ? "Yes" : "No") << '\n';
	std::cout << (SUPERSUBCLASS(tSuper, tJustAClass) ? "Yes" : "No") << '\n';

	std::cout << tConvertion<int, int>::exists << ' ' << tConvertion<int, int>::sameType << '\n';
	std::cout << tConvertion<double, int>::exists << ' ' << tConvertion<double, int>::sameType << '\n';
	std::cout << tConvertion<float, int>::exists << '\n';
	std::cout << tConvertion<char, int>::exists << '\n';
	
	std::cout << tConvertion<char, char*>::exists << '\n';
}

}