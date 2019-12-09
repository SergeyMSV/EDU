#include <iostream>

#include <map>
#include <vector>
#include <utility>

namespace test
{

template<typename T, typename E>
auto Compose(T a, E b) -> decltype(a + b)
{
	return a + b;
}

//template<typename T, typename E>
//decltype(a + b) Compose2(T a, E b) так нельз€, a и b ещЄ не объ€влены
//{
//	return a + b;
//}

void UnitTest_Type()
{
	std::cout << "UnitTest_Type" << std::endl;

	for (auto i = 0; i < 10; i++)
	{
		std::cout << "Preved: " << i << "\n";
	}

	//{
	//	auto RR;//Wrong

	//	decltype(RR) AA;

	//	decltype(int) AB;//Wrong

	//	decltype(auto) AC;//Wrong
	//}

	{
		std::string Str = "asd";

		auto AutoS = Str;

		std::cout << AutoS << std::endl;
	}

	{
		decltype(20) A;

		decltype(20.0) D;

		decltype("sdf") S = "qwe";//определ€ет const char[4], работает только с инициализатором
		//decltype("sdf") S1 = "qweуу";//не работает
		//decltype("sdf") S2 = "qw";//не работает

		decltype('c') C;

		A = 2;
		D = 3;

		std::cout << A << " " << D << std::endl;
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
}

}
