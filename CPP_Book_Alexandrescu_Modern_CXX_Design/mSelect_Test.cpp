//#include "mConvertion.h"
//
//#include <iostream>
//
//namespace Convert
//{
//
//void UnitTest()
//{
//	class tSuper { };
//	class tSuperSub :public tSuper { };
//
//	class tJustAClass { };
//
//	std::cout << (SUPERSUBCLASS(tSuper, tSuperSub) ? "Yes" : "No") << '\n';
//	std::cout << (SUPERSUBCLASS(tSuperSub, tSuper) ? "Yes" : "No") << '\n';
//	std::cout << (SUPERSUBCLASS(tSuper, tJustAClass) ? "Yes" : "No") << '\n';
//
//	std::cout << tConversion<int, int>::exists << ' ' << tConversion<int, int>::sameType << '\n';
//	std::cout << tConversion<double, int>::exists << ' ' << tConversion<double, int>::sameType << '\n';
//	std::cout << tConversion<float, int>::exists << '\n';
//	std::cout << tConversion<char, int>::exists << '\n';
//	
//	std::cout << tConversion<char, char*>::exists << '\n';
//}
//
//}