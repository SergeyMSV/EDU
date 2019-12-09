#include <iostream>

//functor = function object

template <typename T>
class TComparer
{
private:
	bool IsLess;

public:
	TComparer(bool IsLess)
		: IsLess(IsLess)
	{}

	bool operator() (const T& a, const T& b) const
	{
		return IsLess ? a < b : a > b;
	}
};

template <typename T, typename TComparerType>
void sort(T* begin, T* end, const TComparerType& cmp)
{
	for (T* p1 = begin; p1 != end; ++p1)
	{
		for (T* p2 = p1 + 1; p2 != end; ++p2)
		{
			if (cmp(*p2, *p1))
			{
				std::swap(*p1, *p2);
			}
		}
	}
}

int main_lection_3_7_template_sort_functor()
{
	{
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), TComparer<int>(true));

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	{
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), TComparer<int>(false));

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	{//STL
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), std::less<int>());

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	{//STL
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), std::greater<int>());

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "main_lection_3_7_template_sort_functor.end" << std::endl;

	return 0;
}
