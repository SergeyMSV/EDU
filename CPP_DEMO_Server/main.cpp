#include <boost/asio.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include "Benchmark.h"
#include "ServerTCP.h"

int main(int argc, char* argv[])
{
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
					else if (Cmd == "exit")
					{
						IO_Context.stop();

						return;
					}
				}
			});

		std::thread Thread_1([&]()
			{
				IO_Context.run();
			});

		std::thread Thread_2([&]()
			{
				IO_Context.run();
			});

		IO_Context.run();

		ThreadConsole.join();
		Thread_1.join();
		Thread_2.join();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	return 0;
}