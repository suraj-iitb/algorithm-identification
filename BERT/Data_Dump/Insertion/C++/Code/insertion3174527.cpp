#include<iostream>
using namespace std;

//プロトタイプ宣言を忘れない！！
void trace(int A[], int N);
void sort(int A[], int N);

int main() {


	//C++において、nullがどのような扱いなのか
	int boxes[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}

	//最初のものを出力
	trace(boxes, n);
	sort(boxes, n);

	return 0;

	
}

//出力関数
void trace(int A[], int N) {

	for (int i = 0; i < N; i++) {

		if (i > 0) {
			cout << " ";
			
		}
		cout << A[i];
	}

	cout << ("\n");
}

//ソート関数
void sort(int A[], int N) {
	int j, v;
	//比較が行えるのは２番目から
	for (int i = 1; i < N; i++) {
		v = A[i];
		//j<i-1はソート済みの区間
		j = i - 1;
		//比較対象(A[J])があり、それがvよりも大きいとき
		while (j >= 0 && A[j] > v) {
			//ソート済みを１つ後ろにずらす
			A[j + 1] = A[j];
			j--;
		}
		//目的の場所
		A[j + 1] = v;
		trace(A, N);
	}
}
