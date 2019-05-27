#include <iostream>

#include <string>

//namespace lection_6_4
//{

#define lection_6_4_overload_new_delete

#ifdef lection_6_4_overload_new_delete

	void* operator new (size_t sz, double a, int x)
	{
		std::cout << "lection_6_4.operator new with " << sz << std::endl;

		return operator new (sz);
	}

	void operator delete(void* p, double a, int x)
	{
		std::cout << "lection_6_4.operator delete" << std::endl;

		operator delete(p);
	}

#endif//lection_6_4_overload_new_delete

namespace lection_6_4
{
	void Foo()
	{
		int* A = new (1.647, 8) int[100];

		std::cout << "PREVED" << std::endl;

		delete[] A;//[!!!] ÏÐÀÂÈËÜÍÛÉ ÍÅ ÂÛÇÂÀËÑß
	}
}

int main_lection_6_4()
{
	using namespace lection_6_4;

	{
		Foo();
	}

	std::cout << "main_lection_6_4.end" << std::endl;

	return 0;
}