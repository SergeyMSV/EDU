#include <iostream>

#include <algorithm>
#include <vector>

class tClassA
{
	int m_A;

	mutable int m_B;

public:
	tClassA()
	{
		m_A = 4;
		m_B = 0;
	}

	int GetA() const
	{
		++m_B;//mutable (acute for mutexes and the like)

		return m_A;
	}

	int GetB() const
	{
		++m_B;//mutable (acute for mutexes and the like)

		return m_B;
	}
};

int main_lection_3_9_mutable()
{
	{
		const tClassA A;

		std::cout << "Class A" << A.GetA() << A.GetB() << std::endl;
	}

	{//Lambda
		std::vector<int> D1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
		std::vector<int> D2 = { 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };

		//auto cmp = [&D1, D2](int a, int b) -> bool//int
		auto cmp = [&D1, D2](int a, int b) mutable -> bool//int
		{
			D1[0] = D2[0] = 0;//mutable

			//if (a == 12)
			//{
			//	return -1;
			//}

			//return D1[a] < D1[b];

			return a < b;
		};

		std::sort(D1.begin(), D1.end(), cmp);

		std::cout << "Lambda" << std::endl;
	}

	std::cout << "main_lection_3_9_mutable.end" << std::endl;

	return 0;
}
