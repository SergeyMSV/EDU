#include <iostream>

#include <memory>

namespace Task_13
{

int Main()
{
	std::unique_ptr<double> ptr1 = std::make_unique<double>(77.0);
	//std::unique_ptr<double> ptr2 = ptr1;//��� ���������
	//ptr2.reset(std::make_unique<double>(66.0));//�������� - ������ �� ������, � �� ����� unique_ptr

	std::unique_ptr<double> ptr2;//[srg]

	std::cout << ptr2.get() << std::endl;

	return 0;
}

}