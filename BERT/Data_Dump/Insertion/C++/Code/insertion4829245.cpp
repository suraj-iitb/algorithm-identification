#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int A[100];
	for (int i = 0; i < N; i++) { 
		cin >> A[i];
	}

	int count = 0;

	// i...	未ソートの部分列の先頭を示すループ変数。
	// v...	A[i]の値を一時的に保持しておくための変数。
	// j...	ソート済み部分列からvを挿入するための位置を探すループ変数。

	for (int i = 0; i < N; i++) {
		int v;
		v = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;


		for (int x = 0; x < N; x++) {
			if (x) {
				cout << " ";
			}
			cout << A[x];
		}
		cout << endl;
	}
}
