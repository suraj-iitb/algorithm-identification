#include<iostream>
using namespace std;

int bubblesort(int A[], int N) {
	int flag = 1;
	int i = 0;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
				flag = 1;
				count += 1;
			}
		}
		i += 1;

	}
	for (int i = 0; i < N-1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	return count;
}

int main() {
	int N, A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << bubblesort(A, N) << endl;
}
