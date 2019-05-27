#ifndef TEST_SMART_PTR
#define TEST_SMART_PTR

namespace smart_ptr
{

template <typename T>
class tSmartPtr
{
	class tSmartPtrRep
	{
		friend class tSmartPtr;

		T* m_Ptr;

		unsigned short m_Count;

		tSmartPtrRep(const tSmartPtrRep& val)
		{
			m_Ptr = 0;

			m_Count = 1;
		}

		virtual ~tSmartPtrRep()
		{
			delete m_Ptr;
			//delete[] m_Ptr; ??
		}

		tSmartPtrRep& operator = (const tSmartPtrRep& val)
		{
			if (m_Ptr != val.m_Ptr)
			{
				delete m_Ptr;
				//delete[] m_Ptr;

				m_Ptr = val.m_Ptr;
			}

			return *this;
		}

		//bool operator == (const tSmartPtrRep& val)
		//{
		//	return m_Ptr == val.m_Ptr;
		//}
		//bool operator != (const tSmartPtrRep& val);
	};

	tSmartPtrRep *p_Rep;

public:
	tSmartPtr()
	{
		p_Rep = new tSmartPtrRep();
	}

	tSmartPtr(const tBuffer& val)
	{
		p_Rep = val.p_Rep;
		p_Rep->m_Count++;
	}

	~tSmartPtr()
	{
		if (--p_Rep->m_Count == 0)
		{
			delete p_Rep;
		}
	}

	tBuffer& operator = (const tBuffer& val)
	{
		val.p_Rep->m_Count++;

		if (--p_Rep->m_Count == 0)
		{
			delete p_Rep;
		}

		p_Rep = val.p_Rep;

		return *this;
	}

	//bool operator == (const tBuffer& val)
	//{
	//	return *p_Rep == *val.p_Rep;
	//}

	//bool operator != (const tBuffer& val)
	//{
	//	return *p_Rep != *val.p_Rep;
	//}
};

}

#endif//TEST_SMART_PTR
