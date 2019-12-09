#pragma once

#include <string>

namespace test
{
	namespace class_explicit
	{

class tClass
{
	int A;

public:
	tClass()
	{
		A = 0;
	}

	explicit tClass(int a)
	{
		A = a;
	}

	tClass(const tClass& value)
	{

	}
};

	}
}
