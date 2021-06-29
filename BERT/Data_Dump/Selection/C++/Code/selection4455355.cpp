#include <bits/stdc++.h>
using namespace std;

void printarray(int A[], int len) {
	for (int i = 0; i < len - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[len - 1] << endl;
}

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[minj] > A[j]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			cnt++;
		}
	}
	printarray(A, N);
	cout << cnt << endl;
	return 0;
}

