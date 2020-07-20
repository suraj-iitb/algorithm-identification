#include <iostream>
using namespace std;

int A[100];
int N;

int  bubbleSort(int A[], int N) {
	int i = 0;
	int c = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > i; --j) {
			if (A[j - 1] > A[j]) {
				int t = A[j - 1];
				A[j - 1] = A[j];
				A[j] = t;
				flag = 1;
				++c;
			}
		}
		++i;
	}
	return c;
}

void Show(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int c = bubbleSort(A, N);
	Show(A, N);
	cout << c << endl;
}
