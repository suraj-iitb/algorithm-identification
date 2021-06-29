#include <iostream>

using namespace std;

void Selection_Sort() {
	int A[100], min_j, N;
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++) {
		min_j = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[min_j]) {
				min_j = j;
			}
		}
		if (min_j != i) {
			swap(A[i], A[min_j]);
			count++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (i)
			cout << " ";
		cout << A[i];
	}

	cout << endl << count << endl;
}

int main() {
	Selection_Sort();
	return 0;
}
