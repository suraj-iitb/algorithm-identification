#include<iostream>
#include<vector>
int main(void) {
	int N;
	std::cin >> N;
	std::vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	int FLUG=1;
	int NumberChange = 0;
	while (FLUG) {
		FLUG = 0;
		for (int i = N - 1; i > 0; --i) {
			if (A[i] < A[i - 1]) {
				std::swap(A[i], A[i - 1]);
				++NumberChange;
				FLUG = 1;
			}
		}
	}
	for (int i = 0; i < N-1; ++i) {
		std::cout<< A[i]<<" ";
	}
	std::cout << A[N - 1] << std::endl << NumberChange << std::endl;
	//system("pause");
	return 0;
}
