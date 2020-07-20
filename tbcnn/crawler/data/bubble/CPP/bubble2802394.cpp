#include <iostream>
#include <algorithm>
using namespace std;

// A:配列
// N:要素数
void bubbleSort(int* A, int N) {
	bool flag = true; // 逆の隣接要素が存在する
	int counter = 0;

	while (flag) {
		flag = false;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				// 交換する
				swap(A[j], A[j - 1]);
				flag = true;
				counter++;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl << counter << endl;
}

int N;
int A[100];
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	bubbleSort(A, N);
	return 0;
}
