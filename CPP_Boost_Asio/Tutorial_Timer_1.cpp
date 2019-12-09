#include <iostream>
#include <boost/asio.hpp>

void Tutorial_Timer_1()
{
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	t.wait();

	std::cout << "Tutorial_Timer_1" << std::endl;
}