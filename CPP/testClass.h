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

	//Constructors taking only one argument of this type are a special kind of constructor,
	//called initializer - list constructor.
	//Initializer - list constructors take precedence over other constructors when the initializer - list constructor syntax is used
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

protected:
	//virtual void DoSomething1() { }
	virtual void DoSomething2() { }
	virtual void DoSomething3() { }
};

class tClass2 : public tClass
{
	std::string S2;

public:

protected:
	virtual void DoSomething1() { }
	virtual void DoSomething2() override { }//It is to be in base class by all means
	virtual void DoSomething3() override final { }
};

class tClass3 : public tClass2
{
	std::string S3;

public:

protected:
	virtual void DoSomething1() { }
	virtual void DoSomething2() override { }//It is to be in base class by all means
	//virtual void DoSomething3() { }//That's final in base class
};

}
