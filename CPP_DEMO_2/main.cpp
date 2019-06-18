#include <iostream>

void Packet_1();
void Packet_2();

int Reccurrens(int value, int figure, int count)
{
	if (--count > 0)
	{
		return Reccurrens(value + figure, figure, count);
	}

	return value;
}

int main()
{
	//Packet_1();
	//Packet_2();

	for (int i = 0; i < 9; ++i)
	{
		std::cout << Reccurrens(i, i, i) << '\n';
	}

	return 0;
}