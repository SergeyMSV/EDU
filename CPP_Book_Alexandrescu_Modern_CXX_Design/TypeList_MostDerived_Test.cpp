#include "TypeList_MostDerived.h"

#include <iostream>

namespace TL
{

void UnitTest_TypeList_MostDerived()
{
	class tSuper { };
	class tSuperSub :public tSuper { };
	class tSuperSubSub :public tSuperSub { };

	class tSuperSub2 :public tSuper { };

	class tJustAClass { };

	typedef TYPELIST_6(tJustAClass, tSuperSubSub, tSuper, tSuperSub, tSuperSub2, tJustAClass) ListA;
	ListA List;

	typedef MostDerived<ListA, tSuper>::Result TypesA;
	TypesA A;

	std::cout << "PREVED: \n";
}

}