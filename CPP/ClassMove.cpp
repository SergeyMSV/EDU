#include <iostream>

namespace class_move
{

template <class T>
class tClass
{
	T* m_Ptr;

public:
	tClass(T* ptr = nullptr)
		:m_Ptr(ptr)
	{

	}

	tClass(const tClass& value)
	{
		m_Ptr = new T;

		*m_Ptr = *value.m_Ptr;
	}

	tClass(tClass&& value)
		:m_Ptr(value.m_Ptr)// ������� ����� ������������� �� x.m_ptr � m_ptr
	{
		value.m_Ptr = nullptr;
	}

	~tClass()
	{
		delete m_Ptr;//���� m_Ptr = nullptr, ��� ���������, �� ��������
	}

	tClass& operator = (const tClass& value)
	{
		if (&value == this)// �������� �� ����������������
		{
			return *this;
		}

		delete m_Ptr;

		m_Ptr = new T;

		*m_Ptr = *value.m_Ptr;

		return *this;
	}

	tClass& operator = (tClass&& value) noexcept
	{
		if (&value == this)// �������� �� ����������������
		{
			return *this;
		}

		delete m_Ptr;

		m_Ptr = value.m_Ptr;// ������� ����� ������������� �� x.m_ptr � m_ptr
		value.m_Ptr = nullptr;
		//� �������� ���� � ������������ ����������� � ���������� ��������� ������������
		//�� ����������� x.m_ptr �������� nullptr.
		//��� ����� ���������� ������ � � ����� ������, ���� �x� �������� ��������� r-value,
		//�� ����� ��� ������������ � ���������� ����� - ���� ��������, ���� �������� �x�
		//��� ����� ����� ��������� ?
		//
		//����� ����� : ����� �x� ������� �� ������� ���������, �� ����������
		//���������� ��� ����������� x.m_ptr.
		//���� � ���� ������ x.m_ptr ��� ��� ��������� �� ��� �� ������, ��� � m_ptr,
		//�� m_ptr ����������� � ������� ��������� ����� ����������� x.m_ptr.
		//����� ������, ���������� m_ptr, � �������� ����� ����� ����������� (��� ���������),
		//�� �� ������� �������������� ��������� / ����������

		return *this;
	}
};

}

using namespace class_move;

tClass<int> MakeClass(int value)
{
	return tClass<int>(new int(value));
}

void UnitTest_ClassMove()
{
	std::cout << "UnitTest class_move::tClass" << std::endl;

	{
		tClass<int> A;

		std::cout << "A" << std::endl;
	}

	{
		int* PtrA = new int(4);

		//tClass_3<int> A(PtrA);

		delete PtrA;//OK

		std::cout << "A" << std::endl;
	}

	{
		int* PtrA = new int(4);

		tClass<int> A(PtrA);

		//delete PtrA;//EXCEPTION

		std::cout << "A" << std::endl;
	}

	{
		tClass<int> A(new int(4));

		tClass<int> B(new int(5));

		tClass<int> C(new int(6));

		C = B;//copy c_tor
	
		C = MakeClass(8);//move
		//����������� ����������� � �������� ������������ ������������ ����������, ����� 
		//���������� ��� �������� ��� ������������ �������� r - value.
		//���� ����� ���� r - value ����� ������� ��� ��������� �������� (��������� ������).

		std::cout << "A" << std::endl;
	}
}
