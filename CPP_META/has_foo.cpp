#include <iostream>

#include <type_traits>
#include <utility>

//������������ SFINAE ���������������� ��� substitution failure is not an error � �������� ���������:
//��� ����������� ���������� ������� ��������� ������������ �������� �� �������� ������ ����������,
//� ������������� �� ������ ���������� �� �������� ���������� ����������.
//
//��������� �� - �����������, ��� �������� ��� ���:
// - ����� ���� ������� � SFINAE, ��� ����������� ������� � ����������� �������.
// - ��� �������� ��� �������������� ������ ����� �������(type deduction) �� ���������� �������.
// - ��������� ���������� ����� ������������� � ��� ������, ����� �� ���������� ��������������� �� - �� ����������� �������������� ������; ���������� ��� ���� ������������ ��� �� � ��� �� ������, ��� ������.
// - ��������� ����� ������ ������.
// - SFINAE ������������� ������ ��������� �������, ������ � ���� ������� �� ����� ���������.
//
//����������, ��� �� ����� ����������� �������������� ������������ ����� - �� �������,
//��� ������������� ������� ��������� �� ��� ��� ������ �������� ������������� ������.
//��� ���� ���������� �������� ������ ���� ��������, � ���� ������� ������ ������ ��������
//�� ��������� ����� �������.������ ���� ������ ���������� ������ ���������� ��� �����������,
//���� ������ ���� ����������� �������, � �������� SFINAE �� ���������, � ������ ����� ��� ������ ��������.

namespace meta_has_foo
{
	//���������� ������� ������
	//��� ����� ��� ����� �������, ���� �� � ��� ������� �����.
	//������, has_foo �� ������ �������� ������ ����������, ����� �� �������� �� �� ����������.
	//� ������-�� ���������, ���� ����� ��������, ��� ������� ������ � ���� T ���.
	template<typename T>
	class has_foo
	{
		//� �� �� ����� ��������� ������ ����� ����������� ������������ � ������������� ����� ����������.
		//�������� ������������ � � �� �� ����� ����������� �������� � ����������� ���������� �������� ��������.

		static int detect(...);//�������� ("..." - ��������)
		//static void detect(...);//�������� ("..." - ��������)

		template<typename U> 
		static decltype(std::declval<U>().foo(42)) detect(const U&);//��������
		//static decltype(std::declval<T>().foo(42)) detect(const T&);//Compiller error, 7 pcs.

		//� ��������� ��� ������������� �������� ������ void, � � ���������� � ���, ������������ �������,
		//�� ���� � ������, ����� ����� ������������� ����� ����������� ��� �� ����� void.
		//��� �� �����. ������-�� �� ��� ��������� ��� �� int. ����� �������� ���������� �������:
		//���� ����� detect �� ������� T ����� ��� void, �� �������� ��������� � ����� ���������
		//������������� ����� �����������. ���� ��� ������, �� ���� ��������� ���������, ���� �����
		//����������, ��������� �� ����� ���������, �� ���������� ���-�� �� ��.

	public:
		static constexpr bool value = std::is_same<void, decltype(detect(std::declval<T>()))>::value;
	};

	struct tClass1
	{
		void foo(int a) { }
	};

	struct tClass2
	{
		void foo() { }
	};

	struct tClass3
	{
		bool foo(int a) { return false; }
	};
}

int main_meta_has_foo()
{
	using namespace meta_has_foo;

	//has_foo<int>::detect();

	std::cout << std::boolalpha;
	std::cout << "is_same:" << std::endl;
	std::cout << "int     " << has_foo<int>::value << std::endl;
	std::cout << "tClass1 " << has_foo<tClass1>::value << std::endl;
	std::cout << "tClass2 " << has_foo<tClass2>::value << std::endl;
	std::cout << "tClass3 " << has_foo<tClass3>::value << std::endl;

	return 0;
}
