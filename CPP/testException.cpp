#include <iostream>

#include <chrono>
#include <mutex>
#include <stdexcept>
#include <thread>

namespace test
{

static std::mutex gMtx;//со static может быть использован только в этом файле

void ThreadFunc_PrintEven(int x) //noexcept - если это есть - на throw будет ABORT
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
		std::lock_guard<std::mutex> LocalGuard(gMtx);

		ThreadFunc_PrintEven(x);
	}
	catch (std::logic_error & err)
	{
		std::lock_guard<std::mutex> LocalGuard(gMtx);

		std::cout << "[exception caught]: " << err.what() << std::endl;
	}
}

void UnitTest_Exception()
{
	std::cout << "UnitTest_Exception" << std::endl;

	{
		size_t ThreadQty = 10;

		std::thread* Threads = new std::thread[ThreadQty];

		for (auto i = 0; i < ThreadQty; ++i)
		{
			Threads[i] = std::thread(ThreadFunc, i);
		}

		for (auto i = 0; i < ThreadQty; ++i)
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

	{
		for (int i = 0; i < 3; ++i)
		{
			try
			{
				switch (i)
				{
				case 0:
				{
					throw 'A';
				}
				case 1:
				{
					throw 34;
				}
				case 2:
				{
					throw "12312313";
				}
				}
			}
			catch (char ex)
			{
				std::cout << "Exception char =" << ex << std::endl;
			}
			catch (int ex)
			{
				std::cout << "Exception int =" << ex << std::endl;
			}
			catch (...)
			{
				std::cout << "Exception ..." << std::endl;
			}
		}
	}
}

}
