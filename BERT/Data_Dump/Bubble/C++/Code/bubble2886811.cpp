#include "bits/stdc++.h"
using namespace std;

void print(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int bubbleSort(int A[], int N) {
	int i=0, flag = 1, count=0;
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = 1;
				count++;
			}
		}
		i++;
	}
	return count;
}

int main() {
	int N, A[100], count;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	count = bubbleSort(A, N);
	print(A, N);
	cout << count << endl;
}
