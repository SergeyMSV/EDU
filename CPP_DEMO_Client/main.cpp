#include <boost/asio.hpp>
#include <iostream>
#include "PacketBNTBX2.h"
#include "PacketBNTBX2_Msg0802.h"

#include <boost/array.hpp>//TEST

int main()
{
	using boost::asio::ip::tcp;

	try
	{
		boost::asio::io_context IO_Context;

		tcp::endpoint Endpoint(boost::asio::ip::address_v4::loopback(), 50025);

		tcp::socket Socket(IO_Context);

		while (true)
		{
			try
			{
				Socket.connect(Endpoint);

				tUInt8 PacketID = 0;

				while (true)
				{
					tPacketBNTBX2 Packet;

					tMsgBNTBX0802Cmd Msg(PacketID++);

					Packet.SetMsg<tMsgBNTBX0802Cmd>(Msg);

					tVectorUInt8 PacketVector = Packet.ToVector();

					Socket.send(boost::asio::buffer(PacketVector));

					/////////////////
					//boost::array<char, 128> buf;

					//boost::system::error_code error;

					//size_t len = Socket.read_some(boost::asio::buffer(buf), error);

					//std::cout << " Received: " << len << '\n';
					//////////////////

					boost::asio::steady_timer Timer(IO_Context, boost::asio::chrono::seconds(1));

					Timer.wait();
				}
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << '\n';

				Socket.close();
			}

			boost::asio::steady_timer Timer(IO_Context, boost::asio::chrono::seconds(5));
			
			Timer.wait();
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	return 0;
}