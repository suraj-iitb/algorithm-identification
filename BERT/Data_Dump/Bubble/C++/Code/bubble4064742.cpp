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

int64_t bubbleSort(int64_t A[], int64_t N) {
	int64_t sw = 0;
	bool sorted = true;
	for (int64_t i = 0; sorted; i++) {
		sorted = false;
		for (int64_t j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				std::swap(A[j], A[j - 1]);
				sorted = true;
				sw++;
			}
		}
	}
	return sw;
}

void solve()
{
	int64_t A[100], N, sw;
	std::cin >> N;
	for (int64_t i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	sw = bubbleSort(A, N);

	trace(A, N);
	std::cout << sw << std::endl;

	return;
}

int main()
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
