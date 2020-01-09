#pragma once

template <typename T>
class Functor
{
	T m_Fun = nullptr;

public:
	explicit Functor(T fun) :m_Fun(fun) { }

	T Get() { return m_Fun; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////

#include "TypeList_Lists.h"
#include "TypeList_Index.h"

#include <memory>

namespace TL
{

template <typename TResult, class TList>
class FunctorImpl;

template <typename TResult>
class FunctorImpl<TResult, NullType>
{
public:
	virtual ~FunctorImpl() {}
	virtual TResult operator()() = 0;
	//virtual FunctorImpl* Clone() const = 0;
};

template <typename TResult, typename TP1>
class FunctorImpl<TResult, TYPELIST_1(TP1)>
{
public:
	virtual ~FunctorImpl() {}
	virtual TResult operator()(TP1) = 0;
	//virtual FunctorImpl* Clone() const = 0;
};

template <typename TResult, typename TP1, typename TP2>
class FunctorImpl<TResult, TYPELIST_2(TP1, TP2)>
{
public:
	virtual ~FunctorImpl() {}
	virtual TResult operator()(TP1, TP2) = 0;
	//virtual FunctorImpl* Clone() const = 0;
};

//...

template <typename TResult, class TList>
class Functor
{
	typedef typename TypeAt<TList, 0>::Result TParm1;//Originally TypeAtNoneStrict
	typedef typename TypeAt<TList, 1>::Result TParm2;//Originally TypeAtNoneStrict

	typedef FunctorImpl<TResult, TList> Impl;

public:
	Functor() { }
	//Functor(const Functor&);
	//Functor& operator = (const Functor&);
	explicit Functor(std::auto_ptr<Impl> spImpl) :m_spImpl(spImpl) {}

	TResult operator()()
	{
		return (*m_spImpl)();
	}

	TResult operator()(TParm1 p1)
	{
		return (*m_spImpl)(p1);
	}

	TResult operator()(TParm1 p1, TParm2 p2)
	{
		return (*m_spImpl)(p1, p2);
	}

private:
	std::auto_ptr<Impl> m_spImpl;
};

}
