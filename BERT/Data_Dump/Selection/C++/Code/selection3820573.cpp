#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int SelectionSort(int A[], int n) {
	int count = 0; //交換回数記録用
	int i = 0; //未ソートの要素の先頭のインデックスを示すループ変数
	int j = 0; //最小の要素のインデックスを探すためのループ変数
	int minj = 0; //最小の要素のインデックスを格納する変数

	//何か「i < n - 1」としてたけど普通に「i < n」で良かった
	for (i; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		swap(A[i], A[minj]);
		if (i != minj) {
			count++;
		}
	}

	return count;
}

void Output(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << A[i];
	}
}

int main() {
	int A[MAX];
	int n;
	int count;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	count = SelectionSort(A, n);
	Output(A, n);
	cout << endl;
	cout << count << endl;

	return 0;
}
