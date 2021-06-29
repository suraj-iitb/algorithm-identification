#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];// マージソートで使う左半分、右半分の配列
int cnt; // 交換回数

// 分割した要素を統治（マージ）する
void merge(int A[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = R[n2] = SENTINEL; // 配列末尾に巨大な値を入れておく
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++; // 交換回数インクリメント
		// 左配列の先頭と右配列の先頭で小さいほうを元配列に追加する
		if (L[i] <= R[j]) { // i: 左配列の先頭を指す, j: 右配列の先頭を指す
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(int A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

int main() {
	int A[MAX], n, i; // ソート対象配列Aと要素数と制御変数
	cnt = 0; // 交換回数の初期化

	cin >> n;
	for (i = 0; i < n; i++) cin >> A[i];

	mergeSort(A, n, 0, n);

	for (i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << cnt << endl;

	return 0;
}
