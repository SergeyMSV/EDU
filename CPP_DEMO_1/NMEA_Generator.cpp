#include "Header.h"

#include <iomanip>
#include <iostream>

#include <atomic>
#include <chrono>
#include <ctime>
#include <functional>
#include <mutex>
#include <string>
#include <thread>

//$GPGGA,142205.000,5555.455177,N,03745.106320,E,1,12,0.75,156.123,M,14.351,M,,*6B
//$GNGLL,5555.455177,N,03745.106320,E,142205.000,A,A*41
//$GNGSA,A,3,12,24,02,06,29,14,32,31,03,25,19,,1.10,0.75,0.81*17
//$GNGSA,A,3,83,,,,,,,,,,,,1.10,0.75,0.81*1C
//$GPGSV,4,1,13,12,78,122,29,25,54,287,46,02,51,135,21,06,43,067,28*79
//$GPGSV,4,2,13,24,28,186,45,29,20,239,20,14,19,302,41,19,19,063,23*71
//$GPGSV,4,3,13,31,15,321,19,32,14,279,19,03,06,006,25,17,02,063,*77
//$GPGSV,4,4,13,45,,,*7A
//$GLGSV,3,1,09,82,85,107,,80,68,173,,73,54,310,25,83,34,217,30*67
//$GLGSV,3,2,09,81,34,045,13,65,16,016,,79,11,149,,72,10,329,*6D
//$GLGSV,3,3,09,66,03,067,*5E
//$GNRMC,142205.000,A,5555.455177,N,03745.106320,E,0.07,62.90,190417,,,A*46
//$GPVTG,62.90,T,,M,0.07,N,0.12,K,A*04

namespace NMEA
{
	void UpdateDataSet(std::shared_ptr<tDataSet> dataSet, const tm& dateTime, const std::chrono::milliseconds& timePoint_ms, const std::chrono::duration<double, std::milli>& elapsed)
	{
		std::lock_guard<std::mutex> Mtx(dataSet->Mutex);

		dataSet->DateTime.Year = dateTime.tm_year - 100;
		dataSet->DateTime.Month = dateTime.tm_mon;
		dataSet->DateTime.Day = dateTime.tm_mday;
		dataSet->DateTime.Hour = dateTime.tm_hour;
		dataSet->DateTime.Minute = dateTime.tm_min;
		dataSet->DateTime.Second = dateTime.tm_sec;
		dataSet->DateTime.Millisecond = timePoint_ms.count() % 1000;
		dataSet->Valid = true;
		dataSet->Elapsed = elapsed.count();
		dataSet->Count++;
	}

	void Make_NMEA(std::atomic<tThreadControl>& threadControl, std::shared_ptr<tDataSet> dataSet)
	{
		using namespace std::chrono;
		using namespace std::chrono_literals;

		auto OperationStart = high_resolution_clock::now();

		auto OperationEnd = high_resolution_clock::now();

		duration<double, std::milli> OperationElapsed = OperationEnd - OperationStart;

		tm DateTime;

		milliseconds TimePoint_ms;

		auto Bound_UpdateDataSet = std::bind(UpdateDataSet, std::ref(dataSet), std::cref(DateTime), std::cref(TimePoint_ms), std::cref(OperationElapsed));

		while (true)
		{
			switch (threadControl)
			{
			case tThreadControl::Exit:
			case tThreadControl::Exit1:
			{
				return;
			}
			}

			OperationStart = high_resolution_clock::now();

			auto TimePoint = system_clock::now();

			TimePoint_ms = duration_cast<milliseconds>(TimePoint.time_since_epoch());

			std::time_t DateTimeRaw;//OLD-FASHIONED ??

			DateTimeRaw = system_clock::to_time_t(TimePoint);//OLD-FASHIONED ??

			gmtime_s(&DateTime, &DateTimeRaw);//OLD-FASHIONED ??

			OperationEnd = high_resolution_clock::now();

			OperationElapsed = OperationEnd - OperationStart;

			Bound_UpdateDataSet();

			//std::cout << "Elapsed " << OperationElapsed.count() << " ms\n";

			std::this_thread::sleep_for(0.001s);
		}
	}

}