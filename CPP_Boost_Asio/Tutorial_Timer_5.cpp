#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

namespace tutorial_timer_5
{

class tPrinter
{
	boost::asio::strand<boost::asio::io_context::executor_type> strand_;
	boost::asio::steady_timer timer1_;
	boost::asio::steady_timer timer2_;
	int count_;

public:
	tPrinter(boost::asio::io_context& io)
		: strand_(boost::asio::make_strand(io)),
		timer1_(io, boost::asio::chrono::seconds(1)),
		timer2_(io, boost::asio::chrono::seconds(1)),
		count_(0)
	{
		timer1_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&tPrinter::print1, this)));

		timer2_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&tPrinter::print2, this)));
	}

	~tPrinter()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}

	void print1()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 1: " << count_ << std::endl;

			++count_;

			timer1_.expires_at(timer1_.expiry() + boost::asio::chrono::seconds(1));

			timer1_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&tPrinter::print1, this)));
		}
	}

	void print2()
	{
		if (count_ < 10)
		{
			std::cout << "Timer 2: " << count_ << std::endl;

			++count_;

			timer2_.expires_at(timer2_.expiry() + boost::asio::chrono::seconds(1));

			timer2_.async_wait(boost::asio::bind_executor(strand_, boost::bind(&tPrinter::print2, this)));
		}
	}
};

}

void Tutorial_Timer_5()
{
	using namespace tutorial_timer_5;

	boost::asio::io_context io;

	tPrinter p(io);

	boost::thread t(boost::bind(&boost::asio::io_context::run, &io));

	io.run();

	t.join();
}