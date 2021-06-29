// Algorithm.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <algorithm>

using namespace std;


void Trace(int a[], int b) {
	for (int i = 0; i < b; i++) {
		if (i != 0) cout << ' ' << flush;
		cout << a[i] << flush;
	}
	cout << endl;
}


void Insertation_Sort(int a[], int b) {
	for (int i = 1; i < b; i++) {
		int v, j;
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		Trace(a, b);
	}
}//挿入ソート
void Bubble_Sort(int a[], int b) {
	int count = 0;
	bool flag = true;
	int c;
	while (flag) {
		flag = false;
		for (int i = b - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				c = a[i];
				a[i] = a[i - 1];
				a[i - 1] = c;
				flag = true;
				count++;
			}
		}
	}
//	cout << count << endl;



}
int Selection_Sort(int a[], int b) {
	int c, count = 0;
	for (int i = 0; i < b; i++) {
		int minj = i;
		for (int j = i; j < b; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		c = a[i];
		a[i] = a[minj];
		a[minj] = c;
		if (minj != i) count++;
	}

	return count;

}



int main()
{
	int a[1004] = {};
	int b; cin >> b;
	for (int i = 0; i < b; i++)cin >> a[i];



	int count = Selection_Sort(a, b);
	Trace(a, b);
	cout << count << endl;
}

/* 
bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
2   flag = 1 // 逆の隣接要素が存在する
3   while flag
4     flag = 0
5     for j が N-1 から 1 まで
6       if A[j] < A[j-1]
7         A[j] と A[j-1] を交換
8         flag = 1
*/
