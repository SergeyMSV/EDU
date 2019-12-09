#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

namespace task_01_01
{

class tDate
{
	int m_Year = 0;
	int m_Month = 0;
	int m_Day = 0;

public:
	tDate(int year, int month, int day) :m_Year(year), m_Month(month), m_Day(day) { }
	tDate(const std::string& date)
	{
		//12/31/95...
	}

	bool operator == (const tDate& value)
	{
		return m_Year == value.m_Year && m_Month == value.m_Month && m_Day == value.m_Day;
	}

	friend std::istream& operator>>(std::istream& in, tDate& date);
	friend std::ostream& operator<<(std::ostream& out, const tDate& date);
};

std::istream& operator>>(std::istream& in, tDate& date)
{
	in >> date.m_Year;
	in >> date.m_Month;
	in >> date.m_Day;

	return in;
}

std::ostream& operator<<(std::ostream& out, const tDate& date)
{
	out << date.m_Year << '/' << date.m_Month << '/' << date.m_Day;

	return out;
}

void Task()
{
	using namespace task_01_01;

	std::vector<tDate> e;

	//std::copy(std::istream_iterator<tDate>(std::cin), std::istream_iterator<tDate>(), std::back_inserter(e));//[E] it will work forever

	//---start
	e.push_back(tDate(1982, 1, 17));
	e.push_back(tDate(1983, 1, 17));
	e.push_back(tDate(1984, 1, 17));
	e.push_back(tDate(1985, 1, 17));
	e.push_back(tDate(1986, 1, 17));
	e.push_back(tDate(1987, 1, 17));
	e.push_back(tDate(1988, 1, 17));
	e.push_back(tDate(1989, 1, 17));
	e.push_back(tDate(1990, 1, 17));
	e.push_back(tDate(1991, 1, 17));
	//---end

	std::vector<tDate>::iterator first = std::find(e.begin(), e.end(), tDate(1983, 1, 17));
	std::vector<tDate>::iterator last = std::find(e.begin(), e.end(), tDate(1990, 1, 17));//[E]no guarantee that the dates are sorted that's why last can be less than first

	*last = tDate(1991, 1, 17);//[E]last can be equal to end()

	std::copy(first, last, std::ostream_iterator<tDate>(std::cout, "\n"));

	std::cout << "Preved\n";
}

}