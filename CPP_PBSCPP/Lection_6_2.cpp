#include <iostream>

#include <string>

namespace lection_6_2
{

class tClassA
{
	char* m_Array;

	char m_Array1[4096];

public:
	tClassA()
	{
		m_Array = 0;

		std::cout << "tClassA::c_tor_1" << std::endl;
	}

	explicit tClassA(const int capacity)
	{
		m_Array = new char[capacity];

		std::cout << "tClassA::c_tor_2" << std::endl;
	}

	~tClassA()
	{
		delete[] m_Array;

		std::cout << "tClassA::d_tor" << std::endl;
	}
};

}

int main_lection_6_2()
{
	using namespace lection_6_2;

	{
		void* Ptr = malloc(sizeof(tClassA));

		if (Ptr != nullptr)
		{
			tClassA* A = new (Ptr) tClassA(200);

			//...

			A->~tClassA();

			free(Ptr);
		}
	}

	{
		//void* Ptr = malloc(1);//[!!!] если памяти меньше чем нужно, в new не определяется, виснет free
		//exception не вылеатает почему-то...
		void* Ptr = malloc(1000);

		if (Ptr != nullptr)
		{
			tClassA* A = new (Ptr) tClassA(200);

			//...

			A->~tClassA();

			free(Ptr);
		}
	}

	std::cout << "main_lection_6_2.end" << std::endl;

	return 0;
}