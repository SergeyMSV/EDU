#include <iostream>
#include <boost/asio.hpp>

static void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Tutorial_Timer_2" << std::endl;
}
	
void Tutorial_Timer_2()
{
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	t.async_wait(&print);

	io.run();
}