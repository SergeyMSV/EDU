#include <iostream>

#include <functional>

struct Foo
{
	void print(int i) const { std::cout << i << std::endl; }
};

void print_num(int i)
{
	std::cout << i << std::endl;
}

int main_lection_3_11_std_function()
{
	{
		std::function<void(int)> f_display = print_num;

		f_display(1);
	}

	{
		std::function<void()> f_display_2 = []() { print_num(2); };

		f_display_2();
	}

	{
		std::function<void(const Foo&, int)> f_add_display = &Foo::print;

		f_add_display(Foo(), 1);
	}

	{
		using T = std::vector<std::function<bool(int)>>;

		T Funcs;//pattern chain of responsibility... may be...

		Funcs.reserve(5);

		Funcs.emplace_back([=](int a) { return a == 0; });
		Funcs.emplace_back([=](int a) { return a == 1; });
		Funcs.emplace_back([=](int a) { return a == 2; });
		Funcs.emplace_back([=](int a) { return a == 3; });
		Funcs.emplace_back([=](int a) { return a == 4; });
			
		for (const auto& i : Funcs)
		{
			std::cout << "A == 3 " << i(3) << std::endl;
		}
	}

	std::cout << "main_lection_3_11_std_function.end" << std::endl;

	return 0;
}
