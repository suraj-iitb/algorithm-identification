#include <iostream>
#include <algorithm>
using namespace std;

// 挿入ソート
void insertionSort(int* A, int N) {
	for (int i = 1; i < N; i++) {
		int v = A[i]; // 処理する値
		int j = i - 1; // 値より前(左はソート済)

		// 左がv以上なら続ける
		while (j >= 0 && A[j] > v) {
			// 右にもってく
			A[j + 1] = A[j];
			j--;
		}

		// 止まったポジションに持っていく
		A[j + 1] = v;

		// 出力
		for (int i = 0; i < N; i++) {
			cout << A[i];
			if (i != N - 1) cout << " ";
		}
		cout << endl;
	}
}

int N;
int R[100];
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> R[i];
	}

	// 入力直後の出力
	for (int i = 0; i < N; i++) {
		cout << R[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl;

	insertionSort(R, N);

	return 0;
}
