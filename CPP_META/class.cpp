template <int N = 5>
class tClass
{
public:
	tClass<N - 1> m_Class;

public:
	tClass() = default;
};

template <>
class tClass<0>
{
public:
	int m_D = 123;

public:
	tClass() = default;
};

void UnitTest_Class()
{
	tClass<> A;

	auto A_D = A.m_Class.m_Class.m_Class.m_Class.m_Class.m_D;

	tClass<3> B;

	auto B_D = B.m_Class.m_Class.m_Class.m_D;

	int EE = 10;//Just a statement
}