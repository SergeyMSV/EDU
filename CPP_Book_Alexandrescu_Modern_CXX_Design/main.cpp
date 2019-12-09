namespace Cloneable { void UnitTest(); }
namespace Cloneable2 { void UnitTest(); }
namespace Convert { void UnitTest(); }
namespace Int2Type { void UnitTest(); }
namespace Type2Type { void UnitTest(); }
namespace TL { void UnitTest(); }

int main()
{
	Cloneable::UnitTest();
	Cloneable2::UnitTest();
	Convert::UnitTest();
	Int2Type::UnitTest();
	Type2Type::UnitTest();
	TL::UnitTest();

	return 0;
}