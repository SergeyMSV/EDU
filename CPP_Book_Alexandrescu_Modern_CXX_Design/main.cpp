void UnitTest_StaticCheck();
namespace Cloneable { void UnitTest(); }
namespace Cloneable2 { void UnitTest(); }
namespace Convert { void UnitTest(); }
void UnitTest_Functor();
void UnitTest_Int2Type();
void UnitTest_Type2Type();
namespace TL { void UnitTest(); }

int main()
{
	UnitTest_StaticCheck();
	Cloneable::UnitTest();
	Cloneable2::UnitTest();
	Convert::UnitTest();
	UnitTest_Functor();
	UnitTest_Int2Type();
	UnitTest_Type2Type();
	TL::UnitTest();

	return 0;
}