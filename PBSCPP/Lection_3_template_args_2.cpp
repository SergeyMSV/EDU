#include <iostream>

//получение i-го значения

template <unsigned n, class T, class... Args>
constexpr auto Get(T value, Args... args)
{
	if constexpr (n > sizeof...(args))
	{
		return;
	}
	else if constexpr (n > 0)
	{
		return Get<n - 1>(args...);
	}
	else
	{
		return value;
	}
}

int main_lection_3_template_args_2()
{
	std::cout << Get<2>(1, "abc", 'c', '4', '5') << std::endl;

	std::cout << "main_lection_3_template_args_2.end" << std::endl;

	return 0;
}