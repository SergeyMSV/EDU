#include "Header.h"

#include <iomanip>
#include <iostream>

tDataSet_DateTime::tDataSet_DateTime()
{
	Year = 0;
	Month = 0;
	Day = 0;
	Hour = 0;
	Minute = 0;
	Second = 0;
	Millisecond = 0;
}

tDataSet::tDataSet()
{
	Valid = false;

	Elapsed = 0;

	Count = 0;
}

std::string tDataSet::ToString() const noexcept
{
	//std::string Str;

	//std::stringstream. StrStream(;
	
	std::cout << "$PREVED," <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Hour << "." <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Minute << "." <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Second << "." <<
		std::setw(3) << std::setfill('0') << (int)DateTime.Millisecond << "," <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Year << "." <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Month << "." <<
		std::setw(2) << std::setfill('0') << (int)DateTime.Day << "," <<
		std::setw(8) << std::setfill('0') << std::left << Elapsed << "," <<
		std::setw(2) << std::setfill('0') << std::right << Count <<
		std::endl;

	return std::string();
}
