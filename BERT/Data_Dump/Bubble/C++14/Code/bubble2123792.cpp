#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int bit[101];
void add(int k, int a) {
	while (k <= 100) {
		bit[k] += a;
		k += k&-k;
	}
}
int sum(int x) {
	int s = 0;
	while (x > 0) {
		s += bit[x];
		x -= x&-x;
	}
	return s;
}
int a[100];
int main() {
	int n; cin >> n;
	int res = 0;
	rep(i, n) {
		cin >> a[i];
		res += i - sum(a[i]+1);
		add(a[i] + 1, 1);
	}
	sort(a, a + n);
	rep(i, n) {
		if (i)cout << ' ';
		cout << a[i];
	}
	cout << endl;
	cout << res << endl;
}
