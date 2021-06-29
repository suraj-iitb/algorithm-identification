#include <iostream>
#include <algorithm>
using namespace std;
static const int NUM_MAX = static_cast<int>(1e+2);
static const int VAL_MAX = static_cast<int>(1e+3);

/* Display array elements */
void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << ' ';
		cout << A[i];
	}
	cout << '\n';
}

/* Insertion sort */
void insertionSort(int A[], int N) {
	int j, val;
	for (int i = 1; i < N; i++) {
		val = A[i];
		j = i - 1;
		while ((j >= 0) && (val < A[j])) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = val;
		trace(A, N);
	}
}

int main() {
	int argc, argv[NUM_MAX];

	cin >> argc;

	for (int i = 0; i < argc; i++) cin >> argv[i];
	
	trace(argv, argc);
	insertionSort(argv, argc);

	return 0;
}
