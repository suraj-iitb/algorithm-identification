#include <iostream>

void traceALDS12A(int arr[], int max) {
	for (int i = 0; i < max; ++i) {
		if (i)
			std::cout << " ";
		std::cout << arr[i];
	}
	std::cout << std::endl;
}
int main() {

	int N;
	std::cin >> N;

	int arr[N];
	for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];
	}

	int cnt = 0;

	for (int i = 0; i < N - 1; ++i) {
		for (int j = N - 1; j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
				++cnt;
			}
		}
	}

	traceALDS12A(arr, N);
	std::cout << cnt << std::endl;

	return 0;
}
