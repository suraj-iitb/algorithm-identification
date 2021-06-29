#include <iostream>
using namespace std;

int cnt = 0;

void BubbleSort(int *A, int N) {
	bool flg = true;
	while (flg) {
		flg = false;
		for (int i = N - 1; i >= 1; --i) {
			if (A[i] < A[i - 1]) {
				int tmp;
				tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				flg = true;
				cnt++;
			}
		}
	}
}

int main() {
	int N; cin >> N;
	int A[110];

	for (int i = 0; i < N; ++i) cin >> A[i];

	BubbleSort(A, N);

	for (int i = 0; i < N; ++i) {
		cout << A[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl;

	cout << cnt << endl;
}
