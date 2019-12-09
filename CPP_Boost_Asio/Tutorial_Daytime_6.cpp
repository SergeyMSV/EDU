#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

namespace tutorial_daytime_6
{

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;

	time_t now = time(0);

	char StrTime[80];

	ctime_s(StrTime, sizeof(StrTime), &now);

	return StrTime;
}

class udp_server
{

	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	boost::array<char, 1> recv_buffer_;

public:
	udp_server(boost::asio::io_context& io_context)
		: socket_(io_context, udp::endpoint(udp::v4(), 13))
	{
		start_receive();
	}

private:
	void start_receive()
	{
		socket_.async_receive_from(
			boost::asio::buffer(recv_buffer_), remote_endpoint_,
			boost::bind(&udp_server::handle_receive, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	void handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/)
	{
		if (!error)
		{
			boost::shared_ptr<std::string> message(new std::string(make_daytime_string()));

			socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
				boost::bind(&udp_server::handle_send, this, message,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));

			start_receive();
		}
	}

	void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/)
	{
	}
};

}

void Tutorial_Daytime_6()
{
	using namespace tutorial_daytime_6;

	try
	{
		boost::asio::io_context io_context;

		udp_server server(io_context);

		io_context.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}