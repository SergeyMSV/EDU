#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

void Tutorial_Daytime_4()
{
	using boost::asio::ip::udp;

	try
	{
		boost::asio::io_context io_context;

		udp::resolver resolver(io_context);

		udp::endpoint receiver_endpoint = *resolver.resolve(udp::v4(), "192.168.10.223", "daytime").begin();
		//udp::endpoint receiver_endpoint = *resolver.resolve(udp::v4(), "localhost", "daytime").begin();

		udp::socket socket(io_context);

		socket.open(udp::v4());

		//////

		boost::array<char, 1> send_buf = { { 0 } };

		socket.send_to(boost::asio::buffer(send_buf), receiver_endpoint);

		/////

		boost::array<char, 128> recv_buf;

		udp::endpoint sender_endpoint;

		size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);

		/////

		std::cout.write(recv_buf.data(), len);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}