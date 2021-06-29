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
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int cnt = 0, flg = 1;
	while (flg) {
		flg = 0;
		for (int i = N - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i-1]);
				cnt++;
				flg = 1;
			}

		}
	}
	printarray(A, N);
	cout << cnt << endl;
	return 0;
}

