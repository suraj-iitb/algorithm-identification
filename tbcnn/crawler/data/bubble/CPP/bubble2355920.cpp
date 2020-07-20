#include <iostream>

#define rep(i, first, to) for(ll i = first; i < to; ++i)
#define REP(i, first, to) for(ll i = first; i <= to; ++i)

using namespace std;
typedef long long ll;

int a[101];
int n;

void solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
	}
	int count = 0;
	bool isOk = true;;
	rep(i, 0, n) {
		rep(j, 1, n) {
			if (a[j - 1] > a[j]) {
				swap(a[j], a[j - 1]);
				isOk = false;
				++count;
			}
		}
		if (isOk) break;
	}
	rep(i, 0, n - 1) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	cout << count << endl;
}

int main() {
	solve();
	return 0;
}
