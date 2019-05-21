#include <iostream>

void myprintf(const char* str)
{
	std::cout << str;
}

template <typename T, typename... Targs>
void myprintf(const char* str, T value, Targs... Fargs)
{
	for (; *str != '\0'; ++str)
	{
		if (*str == '%')
		{
			std::cout << value;

			myprintf(str + 1, Fargs...);

			return;
		}

		std::cout << *str;
	}
}

int main_lection_3_template_args_1()
{
	myprintf("% + % = %\n", 1, 2, 3);

	std::cout << "main_lection_3_template_args_1.end" << std::endl;

	return 0;
}