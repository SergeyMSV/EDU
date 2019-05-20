#include <array>

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

	//std::array<int, 3> GetArray2()
	//{
	//	return GetArray();
	//}
}