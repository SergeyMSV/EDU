#ifndef TEST_SMART_PTR_UNIQUE
#define TEST_SMART_PTR_UNIQUE

namespace smart_ptr
{

template <typename T>
class tUniquePtr
{
	T* m_Ptr;

public:
	tUniquePtr()
	{
		m_Ptr = 0;
	}

	explicit tUniquePtr(T* ptr)
	{
		m_Ptr = ptr;
	}

	tUniquePtr(const tUniquePtr& val) = delete;

	tUniquePtr(tUniquePtr&& val) noexcept
	{
		m_Ptr = val.m_Ptr;

		val.m_Ptr = nullptr;
	}

	~tUniquePtr()
	{
		delete m_Ptr;//delete[] m_Ptr;
	}

	tUniquePtr& operator = (const tUniquePtr& val) = delete;

	tUniquePtr& operator = (tUniquePtr&& val) noexcept
	{
		if (&val == this)
		{
			return *this;
		}

		delete m_Ptr;//delete[] m_Ptr;

		m_Ptr = val.m_Ptr;

		val.m_Ptr = nullptr;

		return *this;
	}

	T* Get() const
	{
		return m_Ptr;
	}
};

//template <typename T, typename... TArgs>
//tUniquePtr<T> Make_UniquePtr(TArgs ...args)
//{
//	return tUniquePtr<T>(new T(args...));
//}

template <typename T, typename... TArgs>
tUniquePtr<T> Make_UniquePtr(TArgs&& ...args)
{
	return tUniquePtr<T>(new T(std::forward<TArgs>(args)...));
}

}

#endif//TEST_SMART_PTR_UNIQUE
