#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

void trace(int64_t A[], int64_t N) {
	for (int64_t i = 0; i < N; i++) {
		if (i > 0) std::cout << " ";
		std::cout << A[i];
	}
	std::cout << std::endl;
}

void insertionSort(int64_t A[], int64_t N) {
	for (int64_t i = 1; i < N; i++) {
		int64_t v = A[i];
		int64_t j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, N);
	}
}

void solve()
{
	int64_t N;
	int64_t A[100];
	std::cin >> N;
	for (int64_t i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	trace(A, N);
	insertionSort(A, N);

}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}

