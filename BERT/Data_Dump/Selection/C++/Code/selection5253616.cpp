#include <iostream>
using namespace std;

void selenctionSort(int *A, int n, int *cnt) {
	for (int i = 0; i < n - 1; ++i) {
		int minj = i;
		for (int j = i; j < n; ++j) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) (*cnt)++;
		swap(A[i], A[minj]);
	}
}

int main()
{
	int n;
	cin >> n;
	int* A = new int(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int cnt = 0;
	selenctionSort(A, n, &cnt);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << (i == n - 1 ? "":" ");
	}
	cout << endl << cnt << endl;
	return 0;
}


