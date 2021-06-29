#include<iostream>
#include<cstdio>



int main() {
	int N, v, j;
	int A[100];

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	
	for (int i = 0; i < N; i++) {
		std::cout << A[i];
			if (i >= 0 && i < N - 1) {
				std::cout << " ";
			}
	}
	std::cout << std::endl;
	
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int k = 0; k < N; k++) {
			std::cout << A[k];
			if (k >= 0 && k < N - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
