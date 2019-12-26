#pragma once

namespace test
{

template<class T>
class tClass_3
{
	T* m_Ptr;

public:
	tClass_3(T* ptr = nullptr)
		:m_Ptr(ptr)
	{
		
	}

	tClass_3(const tClass_3& value)
	{
		m_Ptr = new T;

		*m_Ptr = *value.m_Ptr;
	}

	tClass_3(tClass_3&& value)
		:m_Ptr(value.m_Ptr)// ������� ����� ������������� �� x.m_ptr � m_ptr
	{
		value.m_Ptr = nullptr;
	}

	~tClass_3()
	{
		delete m_Ptr;//���� m_Ptr = nullptr, ��� ���������, �� ��������
	}

	tClass_3& operator = (const tClass_3& value)
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

	tClass_3& operator = (tClass_3&& value) noexcept
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