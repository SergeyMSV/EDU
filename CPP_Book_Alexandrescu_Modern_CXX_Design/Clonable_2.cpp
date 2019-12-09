namespace Cloneable2
{

template <typename D, typename B>
class IsDerivedFrom
{
	class No {};
	class Yes { No no[2]; };
	static Yes Test(B*);
	static No Test(...);

	static void Constraint(D* p)
	{
		B* pb = p, pb = p;
	}

public:
	enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

	IsDerivedFrom()
	{
		void(*p)(D*) = Constraint;
	}
};

template <typename T, bool>
class tXImpl
{
	int m_A = 0;
};

template <typename T>
class tXImpl<T, true>
{
	int m_B = 0;

	T m_T;

public:
	tXImpl()
	{
		T CloneT = m_T.Clone();
	}
};

void UnitTest()
{

}

}