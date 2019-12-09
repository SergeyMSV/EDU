#include <iostream>
#include <map>

namespace Task_10
{

int Main()
{
	std::map<bool, int> m;

	m.emplace(0, 30);//0=>false
	m.emplace(1, 20);//1=>true
	m.emplace(2, 10);//2=>true ... already exists

	std::cout << m.size() << std::endl;

	return 0;
}

}