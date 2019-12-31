#pragma once
#include <iostream>

template <int v>
struct Int2Type
{
	enum { value = v };
};
