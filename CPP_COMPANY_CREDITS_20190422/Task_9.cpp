#include <algorithm>
#include <iostream>
#include <vector>

namespace Task_9
{

int Main()
{
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> v2;
	//��� v2 ������ �� ��������, ������� STL ������ �� ��������, �������������
	//�� std::copy_if ������.

	////////////////////////////////////////////////////////////////////
	//v2.reserve(v1.size());//[srg] ��� �� ��������... ������
	v2.resize(v1.size());//[srg]
	////////////////////////////////////////////////////////////////////

	std::copy_if(v1.rbegin(), v1.rend(), v2.begin(), [](int e) {return (e & 1) == 0; });

	for (auto& e : v2)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

	return 0;
}

}