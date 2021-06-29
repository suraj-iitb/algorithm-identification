#include <bits/stdc++.h>
using namespace std;

// スワップ回数を返す
int selectionSort(vector<int>& A) {
	int N = A.size();
	int cnt = 0;
	for (int i=0; i<N; i++) {
		int minj = i;
		for (int j=i; j<N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i=0; i<N; i++) cin >> A[i];

	int cnt = selectionSort(A);

	for (int i=0; i<N; i++) {
		cout << A[i];
		if (i<N-1) cout << ' '; else cout << endl;
	}
	cout << cnt << endl;
	return 0;
}

