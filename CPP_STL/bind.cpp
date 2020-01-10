#include <functional>

#include <iostream>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

void UnitTest_Bind()
{
	using namespace std::placeholders;  // for _1, _2, _3...

	 // demonstrates argument reordering and pass-by-reference
	int n = 7;
	// (_1 and _2 are from std::placeholders, and represent future
	// arguments that will be passed to f1)
	auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);

	n = 10;
	f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused
					// makes a call to f(2, 42, 1, n, 7)


	std::cout << "End\n";
}