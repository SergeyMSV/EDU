#pragma once

template <bool flag, typename T, typename U>
struct Select
{
	typedef T Result;
};

template <typename T, typename U>
struct Select<false, T, U>
{
	typedef U Result;
};
