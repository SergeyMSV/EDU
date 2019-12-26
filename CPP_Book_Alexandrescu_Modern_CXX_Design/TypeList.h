#pragma once

namespace TL
{

class NullType {};

template<class T, class U>
struct Typelist
{
	typedef T Head;
	typedef U Tail;
};

}