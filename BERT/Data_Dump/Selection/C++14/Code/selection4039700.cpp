#include<iostream>
using namespace std;
void fswap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main() {
	int n, a[100], cnt = 0;
	cin >> n;
	for (int i = 0; i<n; ++i) cin >> a[i];
	for (int i = 0; i<n - 1; ++i) {
		int minj = i;
		for (int j = i + 1; j<n; ++j) {
			if (a[j]<a[minj])
				minj = j;
		}
		fswap(&a[i], &a[minj]);
		if (i != minj) ++cnt;
	}
	for (int i = 0; i<n; ++i) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl << cnt << endl;
	return 0;
}
