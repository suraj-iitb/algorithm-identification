#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define INF 1000000001
#define MOD 1000000007

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	REP(i, n) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = key;
		REP(k, n) {
			cout << a[k];
			if (k != n - 1)cout << " ";
		}
		cout << endl;
	}

	return 0;
}
