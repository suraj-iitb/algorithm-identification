#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 2000001
#define VMAX 10000

int main() {
	unsigned short *A, *B;

	int C[VMAX + 1];
	int n, i, j;
	cin >> n;

	// c++ではmallocはキャストしないと代入できない
	A = (unsigned short*)malloc(sizeof(short) * n + 1);
	B = (unsigned short*)malloc(sizeof(short) * n + 1);

	// 初期化
	for (i = 0; i <= VMAX; i++) C[i] = 0;

	// 配列Aの各要素が何回表れるかCに格納する
	for (i = 0; i < n; i++) {
		cin >> A[i + 1];
		C[A[i + 1]]++;
	}

	// 累積和を取ってCを更新する
	for (i = 1; i <= VMAX; i++) C[i] = C[i] + C[i - 1];

	// CからBを生成
	for (j = 1; j <= n; j++) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}

	for (i = 1; i <= n; i++) {
		if (i>1) cout << " ";
		cout << B[i];
	}

	cout << endl;

	return 0;
}
