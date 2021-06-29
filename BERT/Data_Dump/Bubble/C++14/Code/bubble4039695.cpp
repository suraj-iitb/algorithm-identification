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
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = n - 1; i >= 1; --i) {
			if (a[i]<a[i - 1]) {
				fswap(&a[i], &a[i - 1]);
				++cnt;
				flag = true;
			}
		}
	}
	for (int i = 0; i<n; ++i) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl << cnt << endl;
	return 0;
}
