#pragma once

#include <mutex>

enum class tThreadControl
{
	None,
	Abort,
	Exit,

	Exit0,
	Exit1,
	Exit2,
	Exit3,
	Exit4,
};

struct tDataSet_DateTime
{
	unsigned char Year;
	unsigned char Month;
	unsigned char Day;
	unsigned char Hour;
	unsigned char Minute;
	unsigned char Second;
	unsigned short Millisecond;

	tDataSet_DateTime();

	//tDataSet_DateTime(tDataSet_DateTime&& val) noexcept
	//{
	//}

	//tDataSet_DateTime& operator = (tDataSet_DateTime&& val) noexcept
	//{
	//	if (this == &val)
	//	{
	//		return *this;
	//	}

	//	//Year = val.Year;
	//	 std::swap(Year, val.Year);
	//	//Year = std::move(val.Year);

	//	return *this;
	//}
};

struct tDataSet
{
	tDataSet_DateTime DateTime;

	mutable bool Valid;

	double Elapsed;

	mutable unsigned int Count;

	mutable std::mutex Mutex;

	tDataSet();

	//tDataSet(unsigned char year, unsigned char month, unsigned char day, unsigned char hour, unsigned char minute, unsigned char second, unsigned short millisecond, double elapsed)
	//{
	//	Year = year;
	//	Month = month;
	//	Day = day;
	//	Hour = hour;
	//	Minute = minute;
	//	Second = second;
	//	Millisecond = millisecond;

	//	Elapsed = elapsed;

	//	Count++;
	//}

	//tDataSet(tDataSet&& val) noexcept
	//{
	//	DateTime = std::move(val.DateTime);
	//}

	//tDataSet& operator = (tDataSet&& val) noexcept
	//{
	//	DateTime = std::move(val.DateTime);

	//	return *this;
	//}

	std::string ToString() const noexcept;
};