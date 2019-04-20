#pragma once

#include <string>

namespace test
{

class tClass
{
	int A;

	int B;

	std::string S;

public:
	//tClass() = default;

	tClass(tClass&) = delete;

	tClass(int a, int b)
	{
		A = a;

		B = b;
	}

	tClass(std::initializer_list<int> list)
	{
		if (list.size() == 2)
		{
			A = *list.begin();

			B = *(list.begin() + 1);
		}
		else
		{
			A = -1;

			B = -1;
		}
	}

	tClass(int a, int b, std::string s)
	{
		A = a;

		B = b;

		S = s;
	}

	tClass(std::string s)
		:tClass(3, 4)
	{
		S = s;
	}
};

}
