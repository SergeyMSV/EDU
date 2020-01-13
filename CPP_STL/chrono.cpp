#include <chrono>
#include <thread>

#include <iostream>

void f()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int UnitTest_Chrono()
{
	typedef std::chrono::duration<long, std::ratio_multiply<std::ratio<3>, std::chrono::minutes::period>> Hourglass;

	Hourglass A(10);

	std::chrono::hours Hour1(1);

	auto Hour_nsec = std::chrono::nanoseconds(Hour1).count();
	auto Hour_sec = std::chrono::seconds(Hour1).count();
	auto Hour_Hourglass = Hourglass(Hour1).count();

	/////////////////////////////////////////////

	auto t1 = std::chrono::high_resolution_clock::now();
	f();
	auto t2 = std::chrono::high_resolution_clock::now();

	// floating-point duration: no duration_cast needed
	std::chrono::duration<double, std::milli> fp_ms = t2 - t1;

	// integral duration: requires duration_cast
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

	// converting integral duration to integral duration of shorter divisible time unit:
	// no duration_cast needed
	std::chrono::duration<long, std::micro> int_usec = int_ms;

	std::chrono::duration<long, std::micro> int_usec2 = std::chrono::duration_cast<std::chrono::microseconds>(fp_ms);
	auto int_usec3 = std::chrono::duration_cast<std::chrono::microseconds>(fp_ms);

	std::cout << "f() took " << fp_ms.count() << " ms, "
		<< "or " << int_ms.count() << " whole milliseconds "
		<< "(which is " << int_usec.count() << " whole microseconds)" << std::endl;

	return 0;
}