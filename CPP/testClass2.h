#pragma once

#include <string>

namespace test
{

class tClass_2
{
	int A;

public:
	tClass_2()
	{
		A = 0;
	}

	explicit tClass_2(int a)
	{
		A = a;
	}

	tClass_2(const tClass_2& value)
	{
		A = value.A;
	}
};

}
