#include <iostream>

namespace Task_11
{

class A
{
public:
	//inline static int a = 10;//ER: inline ��� �������...

	//***��� ������� ����������� � ���� ������ �� ���������� inline

	const static int a = 10;//[srg]
};

int Main()
{
	A a;

	std::cout << a.a << std::endl;

	return 0;
}

}