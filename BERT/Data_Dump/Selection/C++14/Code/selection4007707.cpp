#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int selectionSort(vector<int>& A, int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj])
				swap(minj, j);
		}
		if (A[i] != A[minj]) {
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
	for (int i = 0; i < N; i++) cin >> A[i];

	int cnt = selectionSort(A, N);
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i < N-1) cout << ' ';
		else cout << endl;
	}
	cout << cnt << endl;
}

