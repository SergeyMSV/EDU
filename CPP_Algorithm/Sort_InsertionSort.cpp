#include <vector>

namespace sort
{
	void InsertionSort()
	{
		std::vector<int> X = { 4,22,6,8,0,5 };

		int N = X.size();

		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j > 0 && X[j - 1] > X[j]; --j)
			{
				std::swap(X[j - 1], X[j]);
			}
		}
	}
}