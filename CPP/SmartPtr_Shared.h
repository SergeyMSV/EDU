#pragma once

namespace smart_ptr
{

template <typename T>
class tSharedPtr
{
	struct tSharedPtrRep
	{
		T* m_Ptr;

		unsigned short m_Count;

		explicit tSharedPtrRep(T* ptr)
		{
			m_Ptr = ptr;
			m_Count = 1;
		}

		~tSharedPtrRep()
		{
			delete m_Ptr;//delete[] m_Ptr; ??
		}
	};

	tSharedPtrRep * m_Rep;

public:
	explicit tSharedPtr(T* ptr)
	{
		m_Rep = new tSharedPtrRep(ptr);
	}

	tSharedPtr(const tSharedPtr& val)
	{
		m_Rep = val.m_Rep;
		m_Rep->m_Count++;
	}

	~tSharedPtr()
	{
		if (--m_Rep->m_Count == 0)
		{
			delete m_Rep;
		}
	}

	tSharedPtr& operator = (const tSharedPtr& val)
	{
		val.m_Rep->m_Count++;

		if (--m_Rep->m_Count == 0)
		{
			delete m_Rep;
		}

		m_Rep = val.m_Rep;

		return *this;
	}

	T* Get() const
	{
		return m_Rep->m_Ptr;
	}
};

//template<typename T, typename... TArgs>
//tSharedPtr<T> Make_SharedPtr(TArgs ...args)
//{
//	return tSharedPtr<T>(new T(args...));
//}

template<typename T, typename... TArgs>
tSharedPtr<T> Make_SharedPtr(TArgs&& ...args)
{
	return tSharedPtr<T>(new T(std::forward<TArgs>(args)...));
}

}
