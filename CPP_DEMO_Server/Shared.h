#pragma once

#include "Packet.h"
#include <chrono>
#include <ctime>

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

	friend std::ostream& operator<< (std::ostream& out, const tMeasureConnection& measureConnection);
};

//[TBD] not inline
inline std::ostream& operator<< (std::ostream& out, const tMeasureConnection& measureConnection)
{
	// display time_point:
	std::time_t TimeStart = std::chrono::system_clock::to_time_t(measureConnection.TimePointStart);
	
	tm TimeinfoStart;
	localtime_s(&TimeinfoStart, &TimeStart);

	out << measureConnection.ID << " "
		<< (measureConnection.Open ? "open  " : "closed") << " "
		<< TimeinfoStart.tm_hour << '.'
		<< TimeinfoStart.tm_min << ':'
		<< TimeinfoStart.tm_sec << ' '
		<< measureConnection.ByteQtySent << ' '
		<< measureConnection.ByteQtyReceived;

	return out;
}


//struct tIConnection
//{
//	virtual void OnReceived(const tVectorUInt8&& data) = 0;
//	void Send(const tVectorUInt8&& data) { };
//};

//struct tIConnectable
//{
//	virtual void OnConnected(tIConnection* connection) = 0;
//};

