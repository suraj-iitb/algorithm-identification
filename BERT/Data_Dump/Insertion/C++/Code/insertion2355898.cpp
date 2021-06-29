#include <iostream>

#define rep(i, first, to) for(ll i = first; i < to; ++i)
#define REP(i, first, to) for(ll i = first; i <= to; ++i)

using namespace std;
typedef long long ll;

int n;
int a[101];
void show(int *p) {
	rep(i, 0, n - 1) {
		cout << p[i] << " ";
	}
	cout << p[n - 1] << endl;
}

void solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
	}
	show(a);
	int v;
	rep(i, 1, n) {
		v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; --j) {
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
		show(a);
	}
}

int main() {
	solve();
	return 0;
}
