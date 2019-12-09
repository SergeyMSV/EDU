#include <iostream>

#include <string>

//namespace lection_6_3
//{

//#define lection_6_3_overload_new_delete

#ifdef lection_6_3_overload_new_delete

	void* operator new (size_t sz)
	{
		std::cout << "lection_6_3.operator new with " << sz << std::endl;

		void* p = malloc(sz);

		if (!p)
		{
			throw std::bad_alloc();
		}

		return p;
	}

	void operator delete(void* p)
	{
		std::cout << "lection_6_3.operator delete" << std::endl;

		free(p);
	}

#endif//lection_6_3_overload_new_delete

namespace lection_6_3
{

	void Foo()
	{
		int* A = new int[100];

		std::cout << "PREVED" << std::endl;

		delete[] A;
	}

}

int main_lection_6_3()
{
	using namespace lection_6_3;

	{
		Foo();
	}

	std::cout << "main_lection_6_3.end" << std::endl;

	return 0;
}