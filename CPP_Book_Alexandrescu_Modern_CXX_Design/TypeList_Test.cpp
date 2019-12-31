namespace TL
{

void UnitTest_TypeList_Append();
void UnitTest_TypeList_Erase();
void UnitTest_TypeList_EraseAll();
void UnitTest_TypeList_Index();
void UnitTest_TypeList_IndexOf();
void UnitTest_TypeList_Length();
void UnitTest_TypeList_Replace();
void UnitTest_TypeList_ReplaceAll();

void UnitTest_TypeList_DerivedToFront();
void UnitTest_TypeList_MostDerived();
void UnitTest_TypeList_NoDuplicates();

void UnitTest_TypeList_GetLinearHierarchy();
void UnitTest_TypeList_GetScatterHierarchy();

void UnitTest()
{
	UnitTest_TypeList_Append();
	UnitTest_TypeList_Erase();
	UnitTest_TypeList_EraseAll();
	UnitTest_TypeList_Index();
	UnitTest_TypeList_IndexOf();
	UnitTest_TypeList_Length();
	UnitTest_TypeList_Replace();
	UnitTest_TypeList_ReplaceAll();

	UnitTest_TypeList_DerivedToFront();
	UnitTest_TypeList_MostDerived();
	UnitTest_TypeList_NoDuplicates();

	UnitTest_TypeList_GetLinearHierarchy();
	UnitTest_TypeList_GetScatterHierarchy();
}

}