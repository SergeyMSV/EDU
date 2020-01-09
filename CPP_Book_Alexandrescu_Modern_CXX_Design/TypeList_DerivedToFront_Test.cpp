#include "TypeList_DerivedToFront.h"

#include <iostream>

class tSuper { };
class tSuperSub :public tSuper { };
class tSuperSubSub :public tSuperSub { };

class tSuperSub2 :public tSuper { };

class tJustAClass { };

namespace TL
{

void UnitTest_TypeList_DerivedToFront()
{
	//class tSuper { };
	//class tSuperSub :public tSuper { };
	//class tSuperSubSub :public tSuperSub { };

	//class tSuperSub2 :public tSuper { };

	//class tJustAClass { };

	typedef TYPELIST_6(tJustAClass, tSuperSubSub, tSuper, tSuperSub, tSuperSub2, tJustAClass) ListA;
	ListA List;

	typedef DerivedToFront<ListA>::Result TypesA;
	TypesA A;

	std::cout << "PREVED: \n";
}

}