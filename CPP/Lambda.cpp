#include <algorithm>
#include <iostream>
#include <vector>

void UnitTest_Lambda()
{
	std::cout << "UnitTest_Lambda" << std::endl;

	{
		std::vector<int> Vector{ 1, 3, 0, 4, 0 };

		std::sort(Vector.begin(), Vector.end(), [](int a, int b) { return a < b; });

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}
	
	{
		std::vector<int> Vector{ 1, 3, 0, 4, 0 };

		std::sort(Vector.begin(), Vector.end(), [=](int a, int b) -> int { return a < b; });

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}

	{
		std::vector<int> Vector{ 1, 3, 0, 4, 0 };

		auto X = [](int a, int b) -> int { return a < b; };

		std::sort(Vector.begin(), Vector.end(), X);

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}

	{
		std::vector<int> Vector{ 1, 3, 0, 4, 0 };

		int C = 0;
		int D = 0;

		auto X = [&C, D](int a, int b) -> int { C = 8; return a < b; };

		std::sort(Vector.begin(), Vector.end(), X);

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}

	{
		std::vector<int> Vector{ 1, 3, 0, 4, 0 };

		auto X = [](auto& a) -> void { a += 2; };

		std::for_each(Vector.begin(), Vector.end(), X);

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}

	{
		int A = 0;
		int B = 3;

		[&A, B](int a) { A = B + a; }(4);

		std::cout << A << std::endl;
	}

	{
		std::vector<int> Vector(10);

		int Index = 0;

		auto X = [&Index] { return ++Index; };

		std::generate(Vector.begin(), Vector.end(), X);

		for (auto i : Vector)
		{
			std::cout << i << std::endl;
		}
	}

	{
		std::vector<int> Vector(10);

		int Index = 0;

		auto X = [&Index](int x) -> int
		{ 
			std::cout << "Lambda " << ++Index + x << std::endl;

			return Index; 
		};

		int Xx = X(4);

		std::cout << "Lambda " << Xx << std::endl;
	}
}
