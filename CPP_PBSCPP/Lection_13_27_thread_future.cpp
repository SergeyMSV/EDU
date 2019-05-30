#include <iostream>

#include <future>
#include <string>

namespace lection_13_27
{
	void ThreadFunc(std::promise<void>& p)
	{
		try
		{
			throw std::runtime_error("exception");
		}
		catch(...)
		{
			p.set_exception(std::current_exception());
		}
	}
}

int main_lection_13_27()
{
	using namespace lection_13_27;

	{
		std::promise<void> P;

		auto Result = P.get_future();

		std::thread Thread(ThreadFunc, std::ref(P));

		Thread.detach();

		try
		{
			Result.get();
		}
		catch (const std::runtime_error& e)
		{
			std::cout << "Preved " << e.what() << std::endl;
		}
	}

	std::cout << "main_lection_13_27.end" << std::endl;

	return 0;
}