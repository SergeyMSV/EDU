#include <boost/asio.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include "Benchmark.h"
#include "ServerTCP.h"

int main(int argc, char* argv[])
{
	std::vector<unsigned int> ListedDevices{ 0x01000001,0x01000004,0x01000005,0x01000008 };

	try
	{
		boost::asio::io_context IO_Context;

		tBenchmark<tServerTCP> BM(IO_Context);

		std::thread ThreadConsole([&]()
			{
				while (true)
				{
					std::string Cmd;

					std::cin >> Cmd;

					if (Cmd == "s")//Cmd == "sockets")
					{
						BM.DisplayConnections();//Thread-safe
					}
				}
			});//[TBD]Close thread correctly

		IO_Context.run();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	return 0;
}