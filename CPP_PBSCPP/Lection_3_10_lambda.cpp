#include <iostream>

#include <algorithm>
#include <vector>

class T
{
private:
	std::vector<int> Data;

public:
	explicit T(const std::vector<int>& data)
		:Data(data)
		//:Data(std::move(data))//no move, just COPY
	{}

	void Do()//Захват данных класса
	{
		auto f = [this](int a, int b)
		{
			return Data[a] < Data[b];
		};
	}
};

constexpr auto add(int y)//C++17 constexpr-lambdas
{
	return [=](int x) { return x + y; };
}

int main_lection_3_10_lambda()
{
	{
		std::vector<int> Data = { 1,2,3,4,5,6 };

		T A(Data);

		A.Do();
	}

	//C++17 constexpr-lambdas
	{
		constexpr auto inc = add(5);

		static_assert(inc(3) == 8);

		auto A = inc;
	}

	std::cout << "main_lection_3_10_lambda.end" << std::endl;

	return 0;
}
