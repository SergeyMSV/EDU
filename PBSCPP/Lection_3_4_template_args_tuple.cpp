#include <iostream>

#include <tuple>
#include <vector>
#include <utility>

//template <typename... Args>
//class Tuple;

//template<>
//class Tuple { };

//template <typename Head, typename... Tail>
//class Tuple<Head, Tail...> : Tuple<Tail...>
//{
//	// ...
//}

std::tuple<int, std::string, int> Func()
{
	return std::make_tuple(123, "asdfgh", 456);
}

std::vector<std::pair<int, std::string>> get_pairs()
{
	return { {1,"qwe"},{2,"rty"},{3,"uio"} };
}

//std::tuple<int, std::string> get_pairs()
//{
//	return std::make_tuple(123, "qwerty");
//}

int main_lection_3_4_template_args_tuple()
{
	auto A = std::make_tuple(1, 10.0, "abc");
	//std::cout << Get<2>(1, "abc", 'c', '4', '5') << std::endl;
	
	//C++11
	{
		int a, b;

		std::string s;

		std::tie(a, s, b) = Func();//returns tuple

		std::cout << "C++11 " << a << s << b << std::endl;
	}

	//C++17
	{
		auto [a, s, b] = Func();//returns tuple

		std::cout << "C++17 " << a << s << b << std::endl;
	}

	// C++17 - структурное связывание
	{
		for (const auto& [key, value] : get_pairs())
		{
			// do smth with key, value
			std::cout << "-> " << key << " " << value << std::endl;
		}
	}

	std::cout << "main_lection_3_4_template_args_tuple.end" << std::endl;

	return 0;
}