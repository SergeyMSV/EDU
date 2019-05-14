#pragma once

#include <iostream>

#include <string>

namespace test
{
	namespace class_override
	{

class tClassBase
{
	int A;

	int B;

	std::string S;

public:
	//tClassBase() = default;

	tClassBase(tClassBase&) = delete;

	tClassBase(int a, int b)
	{
		A = a;

		B = b;
	}

	//Constructors taking only one argument of this type are a special kind of constructor,
	//called initializer - list constructor.
	//Initializer - list constructors take precedence over other constructors when the initializer - list constructor syntax is used
	tClassBase(std::initializer_list<int> list)
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

	tClassBase(int a, int b, const std::string& s)
	{
		A = a;

		B = b;

		S = s;
	}

	tClassBase(const std::string& s)
		:tClassBase(3, 4)
	{
		S = s;
	}

	virtual ~tClassBase()
	{
		std::cout << "tClassBase::~tClassBase" << std::endl;
	}

//protected:
	//virtual void DoSomething1() { }
	virtual void DoSomething2()
	{
		std::cout << "tClassBase::DoSomething2" << std::endl;
	}
	virtual void DoSomething3() { }
};

class tClass2 : public tClassBase
{
	std::string S2;

public:

//protected:
	virtual void DoSomething1() { }
	virtual void DoSomething2() override { }//It is to be in base class by all means
	virtual void DoSomething3() override final { }
};

class tClass3 : public tClass2
{
	std::string S3;

public:

//protected:
	virtual void DoSomething1() { }
	virtual void DoSomething2() override { }//It is to be in base class by all means
	//virtual void DoSomething3() { }//That's final in base class
};

class tClass4 : public tClassBase
{
public:
	tClass4(const std::string& str):tClassBase(str) { }// = default;

//protected:
	void DoSomething1()
	{
		std::cout << "tClass4::DoSomething1" << std::endl;
	}
	void DoSomething2() override//It is to be in base class by all means
	{
		std::cout << "tClass4::DoSomething2" << std::endl;
	}
	//void DoSomething3() { }//That's final in base class
};

	}
}
