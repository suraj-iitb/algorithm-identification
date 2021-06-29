
#include <iostream>
using namespace std;
const int MAX_N = 110;
int i, j, minj, n, x, cnt, k, f, a[MAX_N];
bool flag = 0;
void selectionSort(int A[MAX_N], int N) { // N??????????´??????????0-?????????????????????A
	cnt = 0;
	f = 0;
	for (i = 0; i < N; ++i) {
		minj = i;
		flag = 0;
		for (j = i; j < N; ++j) {
			flag = 0;
			if (A[j] < A[minj]) {
				minj = j;
				f++;
			}
		}

		if (f != 0) {
			x = A[i];
			A[i] = A[minj];
			A[minj] = x;
			cnt++;

		}

		f = 0;

	}
	for (k = 0; k < N - 1; ++k) {
		cout << A[k] << " ";
	}
	cout << A[N - 1] << endl;
	cout << cnt << endl;
}
int main() {

	cin >> n;
	for (j = 0; j < n; ++j) {
		cin >> a[j];
	}
	selectionSort(a, n);
	return 0;
}
