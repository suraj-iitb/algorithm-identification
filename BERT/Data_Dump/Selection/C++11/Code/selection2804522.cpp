#include<iostream>
using namespace std;

int SelectionSort(int N, int *A)
{
	//小さい順
	int count = 0, keep;

	for (int i = 0; i < N; i++) {
		keep = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[keep]) {
				keep = j;
			}
		}
		if (keep != i) {
			swap(A[i], A[keep]);
			count++;
		}
	}

	return count;
}

int main()
{
	int N, A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count = SelectionSort(N, A);

	for (int i = 0;i < N; i++) {
		cout << A[i];
		if (i + 1 != N) {
			cout << " ";
		}
	}

	cout << endl << count << endl;

	return 0;
}
