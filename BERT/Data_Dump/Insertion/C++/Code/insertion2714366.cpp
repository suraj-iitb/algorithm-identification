#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

template<class T> std::ostream& operator<<(std::ostream& o, const std::vector<T>& v)
{
	o << v[0];
	for (unsigned int i = 1; i < v.size(); i++) { o << " " << v[i]; }
	return o;
}

int main()
{
	unsigned int N = 0;
	std::cin >> N;

	std::vector<int> A(N);
	for (unsigned int i = 0; i < N; i++) { std::cin >> A[i]; }

	std::cout << A << std::endl;

	for (unsigned int i = 1; i < N; i++)
	{
		int val = A[i];
		unsigned int cand = i;
		while (cand > 0)
		{
			if (A[cand - 1] < val) { break; }
			A[cand] = A[cand - 1];
			cand--;
		}
		A[cand] = val;

		std::cout << A << std::endl;
	}

	return 0;
}
