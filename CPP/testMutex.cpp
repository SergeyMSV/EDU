#include <iostream>

#include <chrono>
#include <mutex>
#include <thread>

namespace test
{

static std::mutex gMtx;//со static может быть использован только в этом файле
//std::mutex gMtx; - может быть использована во всех файлах проекта, что мешает...

void ThreadFunc_lock(int n, char c)
{
	//using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
	std::lock_guard<std::mutex> LocalGuard(gMtx);
	//gMtx.lock();

	for (auto i = 0; i < n; ++i)
	{
		std::cout << c;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	std::cout << std::endl;

	//gMtx.unlock();
}

void ThreadFunc_try_lock(int n, char c)
{
	while (true)
	{
		if (gMtx.try_lock())
		{
			for (auto i = 0; i < n; ++i)
			{
				std::cout << c;

				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}

			std::cout << std::endl;

			gMtx.unlock();

			return;
		}
		else
		{
			std::cout << '.';

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}

void UnitTest_Mutex()
{
	std::cout << "UnitTest_Mutex" << std::endl;

	{
		std::thread Thread_1(ThreadFunc_lock, 50, '*');
		std::thread Thread_2(ThreadFunc_lock, 50, '$');

		Thread_1.join();
		Thread_2.join();
	}

	{
		std::thread Thread_1(ThreadFunc_try_lock, 50, '*');
		std::thread Thread_2(ThreadFunc_try_lock, 50, '$');

		Thread_1.join();
		Thread_2.join();
	}
}

}
