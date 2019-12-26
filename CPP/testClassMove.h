#pragma once

namespace test
{
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
}