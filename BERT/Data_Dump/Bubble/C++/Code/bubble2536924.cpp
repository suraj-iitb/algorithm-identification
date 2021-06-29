#include<iostream>
using namespace std;

int BubbleSort(int A[], int N) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				sw++;
				flag = 1;
			}
		}
	}
	return sw;
}

int main() {
	int A[100], N, sw;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

	sw = BubbleSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;

	return 0;
}
