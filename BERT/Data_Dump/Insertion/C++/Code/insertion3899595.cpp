#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)


int main() {
	int n;
	cin >> n;
	vector<int> a;
	int tmp;
	REP(i, n) {
		cin >> tmp;
		a.push_back(tmp);
	}

	REP(i, n) {
		if (i == n - 1) cout << a[i] << endl;
		else cout << a[i] << " ";
	}

	int v, j;

	FOR(i, 1, n) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		REP(i, n) {
			if (i == n - 1) cout << a[i] << endl;
			else cout << a[i] << " ";
		}
	}

	return 0;
}

