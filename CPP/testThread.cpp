#include <iostream>

#include <chrono>
#include <thread>

namespace test
{

void ThreadFunc1()
{
	std::cout << "ThreadFunc1" << std::endl;
}

void ThreadFunc2(int i, double d, const std::string& s)
{
	std::cout << "ThreadFunc2" << " i=" << i << " d=" << d << " s=" << s << std::endl;
}

int ThreadFunc3(int i)
{
	std::cout << "ThreadFunc3" << " i=" << i << std::endl;

	return ++i;//ignored...
}

int ThreadFunc4(int i)
{
	std::cout << "ThreadFunc4" << " i=" << i << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(i));

	std::cout << "ThreadFunc4" << " END" << std::endl;

	return i;//ignored...
}

int ThreadFunc5(int i, int n)
{
	std::cout << "ThreadFunc5" << " i=" << i << " n=" << n << std::endl;

	for (auto j = 0; j < n; j++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(i));

		std::cout << "ThreadFunc5" << " count=" << n - j << std::endl;
	}

	std::cout << "ThreadFunc5" << " END" << std::endl;

	return i;//ignored...
}

void UnitTest_Thread()
{
	std::cout << "UnitTest_Thread" << std::endl;

	{
		std::thread Thread_1(ThreadFunc1);

		std::thread::id Thread_1_ID = Thread_1.get_id();

		std::thread Thread_2(ThreadFunc2, 4, 3.14, "example");

		std::thread::id Thread_2_ID = Thread_2.get_id();

		std::thread Thread_3(ThreadFunc3, 4);

		std::thread::id Thread_3_ID = Thread_3.get_id();

		std::thread Thread_4(ThreadFunc4, 4);//sleep_for

		std::thread::id Thread_4_ID = Thread_4.get_id();

		std::thread Thread_5(ThreadFunc5, 4, 5);//sleep_for

		//Thread_5.detach();

		std::thread::id Thread_5_ID = Thread_5.get_id();

		Thread_1.join();
		Thread_2.join();
		Thread_3.join();

		Thread_4.join();
		Thread_5.join();//it's not needed because the thread is detached
	}
}

}
