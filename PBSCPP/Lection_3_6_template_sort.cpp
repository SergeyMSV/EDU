#include <iostream>

template <typename T>
bool CompareTLess(const T& a, const T& b)
{
	return a < b;
}

template <typename T>
bool CompareTGreater(const T& a, const T& b)
{
	return a > b;
}

template <typename T>
void sort(T* begin, T* end, bool (*cmp)(const T&, const T&))
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

int main_lection_3_6_template_sort()
{
	{
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), &CompareTLess<int>);

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	{
		int a[] = { 3, 5, 2, 8, 8, 1 ,0, 15, 12, -1, 3, 4, 7 };

		sort(a, a + sizeof(a) / sizeof(a[0]), &CompareTGreater<int>);

		for (const auto& value : a)
		{
			std::cout << value << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "main_lection_3_6_template_sort.end" << std::endl;

	return 0;
}
