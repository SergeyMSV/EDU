#include "Header.h"

#include <iomanip>
#include <iostream>

#include <atomic>
#include <functional>
#include <mutex>
#include <limits>
#include <string>
#include <thread>

namespace NMEA
{
	void Make_NMEA(std::atomic<tThreadControl>& threadControl, std::shared_ptr<tDataSet> dataSet);
}

int main()
{
	using namespace std::chrono_literals;

	auto DataSet = std::make_shared<tDataSet>();

	std::atomic<tThreadControl> ThreadControl(tThreadControl::None);

	std::thread ThreadNMEAGenerator(NMEA::Make_NMEA, std::ref(ThreadControl), std::ref(DataSet));

	std::thread ThreadApply([&DataSet, &ThreadControl]
		{
			unsigned short Balance_Millisecond = std::numeric_limits<unsigned short>::max();
			unsigned short Balance_Second = std::numeric_limits<unsigned short>::max();

			//auto DataSet_DateTimePrev = std::make_unique<tDataSet_DateTime>();//not needed

			while (true)
			{
				switch (ThreadControl)
				{
				case tThreadControl::Exit:
				case tThreadControl::Exit2:
				{
					return;
				}
				}

				{
					std::lock_guard<std::mutex> Mtx(DataSet->Mutex);

					if (Balance_Millisecond == std::numeric_limits<unsigned short>::max() && DataSet->Valid)
					{
						Balance_Millisecond = DataSet->DateTime.Millisecond;
						Balance_Second = DataSet->DateTime.Second;
					}
					
					if (DataSet->Valid && Balance_Second != DataSet->DateTime.Second)
					{
						if (DataSet->DateTime.Millisecond >= Balance_Millisecond)
						{
							//*DataSet_DateTimePrev = std::move(DataSet->DateTime);

							Balance_Second = DataSet->DateTime.Second;

							std::string Str = DataSet->ToString();

							DataSet->Count = 0;
						}
						//else
						//{
						//	*DataSet_DateTimePrev = std::move(DataSet->DateTime);//not needed
						//}
					}
				}

				std::this_thread::sleep_for(0.1s);
			}
		}
	);//.detach(); - that's not a good idea because ref inside...

	while (true)
	{
		std::string CmdLine;

		std::cin>> CmdLine;

		if (CmdLine == "1")
		{
			ThreadControl = tThreadControl::Abort;
		}
		else if (CmdLine == "exit")
		{
			ThreadControl = tThreadControl::Exit;

			break;
		}
		//else if (CmdLine == "exit0")
		//{
		//	return 0;//Abort
		//}
		else if (CmdLine == "exit1")
		{
			ThreadControl = tThreadControl::Exit1;
		}
		else if (CmdLine == "exit2")
		{
			ThreadControl = tThreadControl::Exit2;
		}

		//std::this_thread::sleep_for(1s);
	}

	ThreadNMEAGenerator.join();//ref inside
	ThreadApply.join();//ref inside

	return 0;
}