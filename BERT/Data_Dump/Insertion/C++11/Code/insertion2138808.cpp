#include <iostream>
void traceALDS11A(int arr[], int max) {
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

	traceALDS11A(arr, N);

	for (int i = 1; i < N; ++i) {
		int v = arr[i];
		for (int j = i - 1; j >= 0; --j) {
			if (v < arr[j]) {
				std::swap(arr[j], arr[j + 1]);
			} else {
				break;
			}
		}
		traceALDS11A(arr, N);
	}

	return 0;
}
