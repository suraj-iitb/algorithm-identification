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

	int mini;
	int count = 0;
	rep(i, 0, n) {
		mini = i;
		rep(j, i + 1, n) {
			if (a[mini] > a[j]) {
				mini = j;
			}
		}
		if (mini != i) {
			++count;
			swap(a[i], a[mini]);
		}
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
