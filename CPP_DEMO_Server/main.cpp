#include <boost/asio.hpp>
#include <vector>
#include <iostream>
#include "PacketBNTBX2.h"
#include "ServerTCP.h"

int main(int argc, char* argv[])
{
	std::vector<unsigned int> ListedDevices{ 0x01000001,0x01000004,0x01000005,0x01000008 };

	try
	{
		boost::asio::io_context IO_Context;

		tServerTCP Server(IO_Context);

		IO_Context.run();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	return 0;
}