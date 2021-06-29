#include <iostream>

using namespace std;

void bubleSort(int *A, int n, int *cnt) {
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; --j) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				*cnt = *cnt + 1;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int *A;
	A = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int cnt = 0;
	bubleSort(A, n, &cnt);
	for (int i = 0; i < n; i++) {
		cout << (i != 0 ? " " : "") << A[i];
	}
	cout << endl << cnt << endl;
	return 0;
}



