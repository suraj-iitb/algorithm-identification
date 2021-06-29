#include <iostream>
using namespace std;
static int N_MAX = 100;

void p(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
}

int bubbleSort(int A[], int N) {
	int count = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = 1; j < N; ++j) {
			if (A[j] < A[j - 1]) {
				int a = A[j];
				A[j] = A[j - 1];
				A[j - 1] = a;
				flag = 1;
				++count;
			}
		}
	}
	return count;
}

int main() {
	int N;
	int A[N_MAX];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int count = bubbleSort(A, N);
	p(A, N);
	cout << count << endl;
}
