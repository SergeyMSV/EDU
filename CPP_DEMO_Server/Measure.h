#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

struct tMeasureConnection//start time, duration, etc.
{
	unsigned int ID = 0;

	bool Open = false;

	std::chrono::time_point<std::chrono::system_clock> TimePointStart;
	std::chrono::time_point<std::chrono::system_clock> TimePointStop;

	size_t ByteQtySent = 0;
	size_t ByteQtyReceived = 0;

	tMeasureConnection() { }

	tMeasureConnection(unsigned int id)
		:ID(id), TimePointStart(std::chrono::system_clock::now())
	{
		Open = true;
	}

	void AddByteQtySent(size_t value)
	{
		if (Open)
		{
			ByteQtySent += value;
		}
	}

	void AddByteQtyReceived(size_t value)
	{
		if (Open)
		{
			ByteQtyReceived += value;
		}
	}

	void Closed()
	{
		if (Open)
		{
			TimePointStop = std::chrono::system_clock::now();

			Open = false;
		}
	}

	unsigned int GetBitrateReceive() const
	{
		std::chrono::duration<unsigned int> Seconds;

		if (Open)
		{
			Seconds = std::chrono::duration_cast<std::chrono::duration<unsigned int>>(std::chrono::system_clock::now() - TimePointStart);
		}
		else
		{
			Seconds = std::chrono::duration_cast<std::chrono::duration<unsigned int>>(TimePointStop - TimePointStart);
		}

		if (Seconds.count() == 0)
		{
			return 0;
		}

		return static_cast<unsigned int>((ByteQtyReceived * 8) / Seconds.count());//Exception. can be divided by zero.
		//return static_cast<double>(ByteQtyReceived * 8) / Seconds.count();
	}

	double GetBitrateSent() const
	{
		std::chrono::duration<double> Seconds;

		if (Open)
		{
			Seconds = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::system_clock::now() - TimePointStart);
		}
		else
		{
			Seconds = std::chrono::duration_cast<std::chrono::duration<double>>(TimePointStop - TimePointStart);
		}

		return static_cast<double>(ByteQtySent * 8) / Seconds.count();
	}

	friend std::ostream& operator<< (std::ostream& out, const tMeasureConnection& measureConnection);
};
