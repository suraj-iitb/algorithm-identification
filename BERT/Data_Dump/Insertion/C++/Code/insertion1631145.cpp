#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < int(n); i++)
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[105];
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cout << a[i] << (i == n - 1 ? '\n' : ' ');
	int k;
	for (int i = 1; i < n; i++) {
		k = a[i];
		int j;
		for (j = i - 1; j<n&&a[j] > k; j--)
			a[j + 1] = a[j];
		a[j + 1] = k;
		for (int i = 0; i < n; i++)
			cout << a[i] << (i == n - 1 ? '\n' : ' ');
	}
	return 0;
}
