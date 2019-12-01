#pragma once

namespace TL
{

class NullType {};
//struct EmptyType {};

template<class T, class U>
struct Typelist
{
	typedef T Head;
	typedef U Tail;
};
///////////////////////////////////////////////////////////////////////////////////////////////////
//typedef Typelist<char, Typelist<int, unsigned char>> CharList;

typedef Typelist<short, Typelist<int, Typelist<long, NullType>>> SignedIntegrals;
///////////////////////////////////////////////////////////////////////////////////////////////////

//Here it's possible to define length of certain TypeLists

template<class TList> struct Length
{
	enum { value = 0 };//????? it's not needed actually
};
template<> struct Length<NullType>
{
	enum { value = 0 };
};
template<class T, class U>
struct Length<Typelist<T, U>>
{
	enum { value = 1 + Length<U>::value };
};
///////////////////////////////////////////////////////////////////////////////////////////////////
}