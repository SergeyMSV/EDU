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
		:m_Ptr(value.m_Ptr)// Передаём право собственности на x.m_ptr в m_ptr
	{
		value.m_Ptr = nullptr;
	}

	~tClass()
	{
		delete m_Ptr;//Если m_Ptr = nullptr, это нормально, всё прокатит
	}

	tClass& operator = (const tClass& value)
	{
		if (&value == this)// Проверка на самоприсваивание
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
		if (&value == this)// Проверка на самоприсваивание
		{
			return *this;
		}

		delete m_Ptr;

		m_Ptr = value.m_Ptr;// Передаём право собственности на x.m_ptr в m_ptr
		value.m_Ptr = nullptr;
		//В примерах выше в конструкторе перемещения и перегрузке оператора присваивания
		//мы присваивали x.m_ptr значение nullptr.
		//Это может показаться лишним — в конце концов, если «x» является временным r-value,
		//то зачем нам беспокоиться о выполнении какой - либо «очистки», если параметр «x»
		//все равно будет уничтожен ?
		//
		//Ответ прост : Когда «x» выходит из области видимости, то вызывается
		//деструктор для уничтожения x.m_ptr.
		//Если в этот момент x.m_ptr все еще указывает на тот же объект, что и m_ptr,
		//то m_ptr превратится в висячий указатель после уничтожения x.m_ptr.
		//Когда объект, содержащий m_ptr, в конечном итоге будет использован (или уничтожен),
		//то мы получим неопределенное поведение / результаты

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
		//Конструктор перемещения и оператор присваивания перемещением вызываются, когда 
		//аргументом для создания или присваивания является r - value.
		//Чаще всего этим r - value будет литерал или временное значение (временный объект).

		std::cout << "A" << std::endl;
	}
}
