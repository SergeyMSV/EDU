namespace meta_difference_type
{
	class tMyDate
	{
		int m_Value;

	public:
		tMyDate(int value)
		{
			m_Value = value;
		}

		typedef float difference_type;

		difference_type operator - (const tMyDate& val)
		{
			return static_cast<difference_type>(m_Value - val.m_Value);
		}

		friend difference_type operator - (const tMyDate& val1, const tMyDate& val2);
	};

	tMyDate::difference_type operator - (const tMyDate& val1, const tMyDate& val2)
	{
		return static_cast<tMyDate::difference_type>(val1.m_Value - val2.m_Value);
	}

	class tClass
	{
		int m_Value;

	public:
		tClass(int value)
		{
			m_Value = value;
		}

		//typedef float difference_type;
	};


	int Difference(int a, int b)
	{
		return a - b;
	}

	template <typename T>
	typename T::difference_type Difference(const T& a, const T& b)
	{
		return a - b;
	}
}

int main_meta_difference_type()
{
	using namespace meta_difference_type;

	auto A = Difference(3, 1);

	auto B = tMyDate(7) - tMyDate(4);

	auto C = Difference(tMyDate(9), tMyDate(2));

	//auto D = Difference(tClass(9), tClass(2));//Compiller error

	//int meta_difference_type::Difference(int,int)': cannot convert argument 1 from 
	//'meta_difference_type::tClass' to 'int'

	return 0;
}