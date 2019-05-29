#include <iostream>

#include <type_traits>
#include <utility>

namespace meta_has_foo
{
	//Определяет наличие метода
	//Про любой тип можно сказать, есть ли в нём искомый метод.
	//Значит, has_foo не должна вызывать ошибки компиляции, какой бы параметр мы ни подставили.
	//А ошибка-то произойдёт, если вдруг окажется, что нужного метода в типе T нет.
	template<typename T>
	class has_foo
	{
		//В то же время «детектор» должен иметь неоспоримое преимущество в «подходящести» перед «подложкой».
		//Наименее приоритетным и в то же время максимально всеядным в определении перегрузок является эллипсис.

		static int detect(...);//Подложка ("..." - эллипсис)

		template<typename U> 
		static decltype(std::declval<U>().foo(42)) detect(const U&);//Детектор

		//У «подложки» тип возвращаемого значения всегда void, а у «детектора» — тип, возвращаемый методом,
		//то есть в случае, когда метод соответствует нашим требованиям… тот же самый void.
		//Так не пойдёт. Сменим-ка мы для «подложки» тип на int. Тогда проверка получается простой:
		//если вызов detect на объекте T имеет тип void, то сработал «детектор» и метод полностью
		//соответствует нашим требованиям.Если тип другой, то либо сработала «подложка», либо метод
		//существует, принимает те самые аргументы, но возвращает что-то не то.

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
