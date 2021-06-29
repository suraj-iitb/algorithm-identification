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

int bubblesort(int A[], int n) {
	bool flag = true;
	int cnt = 0;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = n - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int n; cin >> n;
	int A[110];
	for (int i = 0; i < n; i++) cin >> A[i];
	int ans = bubblesort(A, n);
	trace(A, n);
	cout << ans << endl;
	return 0;
}
