#include <iostream>

#include <chrono>
#include <mutex>
#include <stdexcept>
#include <thread>

namespace test
{

std::mutex gMtx2;

void ThreadFunc_PrintEven(int x)
{
	if (x % 2 == 0)
	{
		std::cout << "x=" << x << " is even" << std::endl;
	}
	else
	{
		throw std::logic_error("not even");
	}
}

void ThreadFunc(int x)
{
	try
	{
		//using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
		std::lock_guard<std::mutex> LocalGuard(gMtx2);

		ThreadFunc_PrintEven(x);
	}
	catch (std::logic_error & err)
	{
		std::lock_guard<std::mutex> LocalGuard(gMtx2);

		std::cout << "[exception caught]: " << err.what() << std::endl;
	}
}

void UnitTest_Exception()
{
	std::cout << "UnitTest_Exception" << std::endl;

	{
		size_t ThreadQty = 10;

		std::thread* Threads = new std::thread[ThreadQty];

		for (int i = 0; i < ThreadQty; ++i)
		{
			Threads[i] = std::thread(ThreadFunc, i);
		}

		for (int i = 0; i < ThreadQty; ++i)
		{
			Threads[i].join();
		}
	}

	{
		std::thread Threads[10];

		int Index = 0;

		for (auto& th : Threads)
		{
			th = std::thread(ThreadFunc, Index++);
		}

		for (auto& th : Threads)
		{
			th.join();
		}
	}
}

}
