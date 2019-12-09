#include <array>
#include <iostream>

namespace cpp11
{

	constexpr int Fact(int n)
	{
		return n == 0 ? 1 : n * Fact(n - 1);
	}

	//static_assert(Fact(7) == 1);//C++17
	//static_assert(Fact(7) == 1, "Fact error...");
	static_assert(Fact(7) == 5040, "Fact error...");//C++11, with C++17 it's possible to omit the message

}

namespace cpp14
{

	constexpr int Fact(int n)
	{
		int Result = 1;

		for (int i = 0; i < n; ++i)
		{
			Result *= i;
		}

		return Result;
	}

	//static_assert(Fact(7) == 5040, "Fact error...");//C++11, with C++17 it's possible to omit the message
}

namespace cpp17
{
	constexpr auto GetArray()
	{
		std::array<int, 3> A = { 1,2,3 };

		A[0] = 5;

		return A;
	}

}

int main_lection_3_1_constexpr()
{
	using namespace cpp17;

	constexpr std::array<int, 3> A = GetArray();

	const std::array<int, 3> B = GetArray();

	std::array<int, 3> C = GetArray();

	std::cout << "cpp17: " << A[2] << std::endl;

	if constexpr (A[1] == 2)
	{
		C[1] = 8;
	}
	else
	{
		C[1] = 12;
	}

	std::cout << "main_local.end" << std::endl;

	return 0;
}
