#include "Measure.h"
#include <cmath>

std::ostream& operator<< (std::ostream& out, const tMeasureConnection& measureConnection)
{
	std::time_t TimeStart = std::chrono::system_clock::to_time_t(measureConnection.TimePointStart);

	tm TimeinfoStart;
	localtime_s(&TimeinfoStart, &TimeStart);

	out << std::setw(2) << std::setfill(' ') << measureConnection.ID << " "
		<< (measureConnection.Open ? "open  " : "closed") << " "
		<< std::setw(2) << std::setfill('0') << TimeinfoStart.tm_hour << '.'
		<< std::setw(2) << std::setfill('0') << TimeinfoStart.tm_min << ':'
		<< std::setw(2) << std::setfill('0') << TimeinfoStart.tm_sec
		<< " In: "
		<< std::setw(5) << std::setfill(' ') << measureConnection.GetBitrateReceive() <<" bps "
		<< std::setw(5) << std::setfill(' ') << measureConnection.ByteQtyReceived<<" B "
		<< " Out: "
		<< std::setw(8) << std::setfill(' ') << std::setprecision(3) << measureConnection.GetBitrateSent()
		<< std::setw(5) << std::setfill(' ') << measureConnection.ByteQtySent;

	return out;
}
