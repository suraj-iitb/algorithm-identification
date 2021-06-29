#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	vector<int> a(N);
	REP(i, N) cin >> a[i];
	FOR(i, 0, N) {
		int j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			int tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
		REP(k, N) {
			if (k < N - 1) cout << a[k] << " ";
			else cout << a[k] << "\n";
		}
	}


	return 0;
}
