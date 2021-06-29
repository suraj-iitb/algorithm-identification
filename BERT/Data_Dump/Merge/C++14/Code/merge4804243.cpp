#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX = 500000; //並べ替える要素の最大数
const int SENTINEL = 2000000000; //番兵

int L[MAX/2 + 2], R[MAX/2 + 2]; //マージの右側部分、左側部分の一時配列
int cnt; //代入回数のカウント

void merge(int A[], int n, int left,int mid, int right) {
	int n1 = mid - left; //左側マージの数
	int n2 = right - mid; //右側マージの数
	for (int i = 0; i < n1; i++) L[i] = A[left + i]; //Aの要素を左側マージに代入
	for (int i = 0; i < n2; i++) R[i] = A[mid + i]; //右側マージで同上
	L[n1] = R[n2] = SENTINEL; //番兵を配置
	int i = 0, j = 0; //iは左側マージのインデックス、jは右側マージのインデックス
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) { //この辺はみりゃわかるだろ
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
		mergeSort(A, n, left, mid); //再帰的
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

int main() {

	int A[MAX], n;
	cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	mergeSort(A,n,0,n);

	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << cnt << endl;

	return 0;
}

