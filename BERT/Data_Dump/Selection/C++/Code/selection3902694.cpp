#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	REP(i, n)	cin >> a[i];

	int minv;
	int minj;
	int tmp;
	int swap_count = 0;
	FOR(i, 0, n - 1) {
		minv = a[i];
		minj = i;
		FOR(j, i + 1, n) {
			if (minv > a[j]) {
				minv = a[j];
				minj = j;
			}
		}
		if (minj != i) {
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			swap_count++;
		}
	}

	REP(i, n) {
		if (i == n - 1) {
			cout << a[i] << endl;
		}
		else cout << a[i] << " ";
	}
	cout << swap_count << endl;

	return 0;
}
