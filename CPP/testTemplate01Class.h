#pragma once

#include <iostream>

namespace test
{
	namespace Template01
	{

template <class T> class tWidget
{
public:
	void Fun()
	{
		std::cout << "Preved!\n";
	}
};

template <>
void tWidget<char>::Fun()
{
	std::cout << "Preved-char\n";
}

template <>
void tWidget<float>::Fun()
{
	std::cout << "Preved-float\n";
}

	}
}