#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int main() {
	int n;
	cin >> n;
	int tmp;
	vector<int> a;
	REP(i, n) {
		cin >> tmp;
		a.push_back(tmp);
	}

	bool flag = true;
	int i=0;
	int ans = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= i+1; j--) {
			if (a[j] < a[j - 1]) {
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
				ans++;
				flag = true;
			}
		}
		i++;
	}

	REP(i, n) {
		if (i == n - 1) { cout << a[i] << endl; }
		else { cout << a[i] << " "; }
	}

	cout << ans << endl;
	return 0;
}
