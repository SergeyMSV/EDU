#include <iostream>

#include <memory>

namespace test
{

void UnitTest_Pointer()
{
	std::cout << "UnitTest_Pointer" << std::endl;

	{
		size_t Size = 10;

		std::auto_ptr<int> Ptr(new int[Size]);

		int* PtrInt = Ptr.get();
		
		for (auto i = 0; i < Size; i++)
		{
			PtrInt[i] = i + 0x10;
		}

		//for (auto i = 0; i < Size; i++)
		//{
		//	std::cout << " 0x" << std::hex << PtrInt[i] << std::endl;
		//}
	}

	{
		size_t Size = 10;

		std::unique_ptr<int> Ptr(new int[Size]);

		int* PtrInt = Ptr.get();

		for (auto i = 0; i < Size; i++)
		{
			PtrInt[i] = i + 0x10;
		}

		//for (auto i = 0; i < Size; i++)
		//{
		//	std::cout << " 0x" << std::hex << PtrInt[i] << std::endl;
		//}

		std::unique_ptr<int> Ptr_2;

		Ptr_2 = std::move(Ptr);
	}

	{
		std::shared_ptr<int> Ptr_1(new int(10));
		std::shared_ptr<int> Ptr_2(new int(11));

		std::cout << *Ptr_1 << " " << *Ptr_2 << std::endl;

		Ptr_2 = Ptr_1;

		std::cout << *Ptr_1 << "" << *Ptr_2 << std::endl;
	}

	{
		std::shared_ptr<int> Ptr_1 = std::make_shared<int>(10);

		std::weak_ptr<int> PtrWeak = Ptr_1;

		std::shared_ptr<int> Ptr_2 = PtrWeak.lock();

		Ptr_1.reset();

		Ptr_1 = PtrWeak.lock();

		std::cout << *Ptr_1 << " " << *Ptr_2 << std::endl;
	}
}

}
