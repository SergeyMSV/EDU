#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace tutorial_timer_4
{

class tPrinter
{
	boost::asio::steady_timer timer_;
	int count_;

public:
	tPrinter(boost::asio::io_context& io)
		: timer_(io, boost::asio::chrono::seconds(1)), count_(0)
	{
		timer_.async_wait(boost::bind(&tPrinter::print, this));
	}

	~tPrinter()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}

	void print()
	{
		if (count_ < 5)
		{
			std::cout << count_ << std::endl;

			++count_;

			timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));

			timer_.async_wait(boost::bind(&tPrinter::print, this));
		}
	}
};

}

void Tutorial_Timer_4()
{
	using namespace tutorial_timer_4;

	boost::asio::io_context io;

	tPrinter p(io);

	io.run();
}