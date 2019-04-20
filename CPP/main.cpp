#include <iostream>

#include <map>
#include <vector>
#include <utility>

namespace test
{

void UnitTest_Lambda();
void UnitTest_tClass();
void UnitTest_tStruct();

}

template<typename T, typename E>
auto Compose(T a, E b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	test::UnitTest_Lambda();
	test::UnitTest_tClass();
	test::UnitTest_tStruct();

    std::cout << "Hello World!\n";

	for (auto i = 0; i < 10; i++)
	{
		std::cout << "Preved: " << i << "\n";
	}

	{
		std::string Str = "asd";

		auto AutoS = Str;

		std::cout << AutoS << std::endl;
	}

	{
		unsigned int A = 10;

		decltype(A) A1;

		A1 = 23;

		std::string B = "asfdasfd";

		decltype(B) B1;

		B1 = "zxcv";

		unsigned int C = 234;

		decltype(A + C) AC1;

		double D = 324.99;

		decltype(A + D) AD1;
	}

	{
		std::vector<int> Vector(10);

		int Index = 0;

		for (auto& i : Vector)
		{
			i = ++Index;
		}
	}

	{
		auto C = Compose(2, 3.14); // C -double

		std::cout << C << std::endl;
	}

	{
		std::map<int, std::string> Map;
		Map[1] = "qwe";
		Map[2] = "asd";
		Map[1] = "xxc";

		std::string Str = Map.at(2);
	}

	{
		int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	}

	{
		std::vector<std::pair<int, std::string>> Vector{ {1, "234"}, {2, "qwer"}, {0, "wert"} };

		for (auto i = Vector.begin(); i != Vector.end(); ++i)
		{
			std::cout << "Medved: " << i->first << " " << i->second << "\n";
		}
	}

	{
		std::vector<int> Vector{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

		Vector.reserve(30);

		Vector.insert(Vector.end(), { 21, 22, 23, 24, 25, 26, 27, 28, 29, 20 });

		for (auto i : Vector)
		{
			std::cout << "for each: " << i << "\n";
		}

		for (auto& i : Vector)
		{
			std::cout << "for each: " << i << "\n";
		}
	}

	{
		std::vector<std::pair<int, std::string>> Vector{ {1, "qwe"}, {2, "rty"}, {3, "uio"}, {2, "p[]"} };

		for (auto i : Vector)
		{
			std::cout << "for each: " << i.first << " " << i.second << "\n";
		}

		for (const auto& i : Vector)
		{
			std::cout << "for each: " << i.first << " " << i.second << "\n";
		}
	}

	{
		int A = 0;

		std::vector<int*> Vector(10, &A);

		std::fill(Vector.begin(), Vector.end(), nullptr);
	}

}
