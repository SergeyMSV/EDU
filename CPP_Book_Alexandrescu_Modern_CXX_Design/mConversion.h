#pragma once

namespace Convert
{

template <class T, class U>
class tConversion
{
	typedef char tSmall;
	class tBig { char dummy[2]; };
	static tSmall Test(const U&);
	static tBig Test(...);
	static T MakeT();

public:
	enum { exists = sizeof(Test(MakeT())) == sizeof(tSmall) };
	enum { sameType = false };
};

template <class T>
class tConversion<T, T>
{
public:
	enum { exists = true };
	enum { sameType = true };
};

}

#define SUPERSUBCLASS(T, U) (Convert::tConversion<const U*, const T*>::exists && !Convert::tConversion<const T*, const void*>::sameType)
#define SUPERSUBCLASS_STRICT(T, U) (SUPERSUBCLASS(T, U) && !Convert::tConversion<const T, const U>::sameType)
