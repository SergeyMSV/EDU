namespace Cloneable
{

template <typename D, typename B>//D derived from B
class tIsDerivedFrom2
{
	static void Constraints(D* p)
	{
		B* pb = p;
	}

protected:
	tIsDerivedFrom2()
	{
		void(*f)(D*) = Constraints;
	}
};

template <typename D>
class tIsDerivedFrom2<D, void>
{
	tIsDerivedFrom2()
	{
		char* p = (int*)0;//Error
	}
};

template <typename T>
class tCloneable
{
	virtual void Clone(T*) = 0
	{

	}
};

class tCloneableValue : public tCloneable<int>
{
	//void Clone()
	//{
	//}
};

//template <typename T>
class tX : tIsDerivedFrom2<tCloneableValue, tCloneable<int>>
{
	//void Clone(T*)
	//{
	//}
};

void UnitTest()
{
	tX x;
	//x.
}

}