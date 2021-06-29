#include <algorithm>
#include <iostream>
using namespace std;

void trace(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int selectionsort(int A[], int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		swap(A[i], A[minj]);
		if (i != minj) cnt++;
	}

	return cnt;
}

int main() {
	int n; cin >> n;
	int A[110];
	for (int i = 0; i < n; i++) cin >> A[i];

	int ans = selectionsort(A, n);
	trace(A, n);
	cout << ans << endl;
	return 0;
}
