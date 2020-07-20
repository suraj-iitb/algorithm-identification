#include<iostream>
using namespace std;

const static int Max = 100;

int bubblesort(int* A, int N) {
	int flag = 1;
	int times = 0;

	while (flag) {
		flag = 0;
		for (int i = N-1; i>0; --i) {
			if (A[i] < A[i - 1]) {
				int v = A[i];
				A[i] = A[i - 1];
				A[i - 1] = v;
				++times;
				flag = 1;

			}
		}
	}

	return times;
}

void show(int* A, int N) {
	for (int i = 0; i < N; ++i) {
		if (i > 0) { cout << ' '; }
		cout << A[i];
	}
	cout << endl;
}

int main() {
	int N;
	int A[Max];

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int times = bubblesort(A, N);

	show(A, N);
	cout << times << endl;

	
}
