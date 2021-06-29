#include<iostream>
#include<utility>
using namespace std;

void output(int *A, int N)
{
	for (int i = 0; i < N; i++) {
		cout << A[i];
		(i + 1 == N) ? cout << endl : cout << " ";
	}
}

//挿入ソート
int main()
{
	int N, A[100];

	//入力
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	output(A, N);

	//挿入ソート
	int j;
	for (int i = 1; i < N; i++) {
		j = i;
		while ((j > 0) && (A[j - 1] > A[j])) {
			//交換
			swap(A[j - 1], A[j]);
			j--;
		}
		output(A, N);
	}

	return 0;
}
