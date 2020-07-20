#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N) {
	int result = 0;
	bool flg = true;

	while (flg) {
		flg = false;
		for (int j = 1; j < N; j++) {
			if (A[j - 1] > A[j]) {
				swap(A[j], A[j - 1]);
				flg = true;
				result += 1;
			}
		}
	}
	return result;
}

int main() {
	int N, *A;
	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) cin >> A[i];

	int cnt = bubbleSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;
}

