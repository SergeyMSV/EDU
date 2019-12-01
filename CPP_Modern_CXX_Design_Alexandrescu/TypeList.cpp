#include "TypeList.h"
#include "TypeList_Lists.h"

namespace TL
{

void UnitTest()
{
	Typelist<int, char> ee;

	auto Size_CharList = Length<SignedIntegrals>::value;

	//CharList e1;

	//SignedIntegrals qw;
	//SignedIntegrals::Tail::Tail::Tail
}
}