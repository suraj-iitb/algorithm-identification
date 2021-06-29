#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int selention_sort(vector< int > &a) {
	int cnt = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		int min_index = i;
		for (int j = min_index; j < (int)a.size(); j++) {
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		if (i != min_index) cnt++;
		swap(a[i], a[min_index]);
	}
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector< int > a(n);
    REP(i, n) cin >> a[i];
    int cnt = selention_sort(a);
    REP(i, n) cout << a[i] << (i == n - 1 ? '\n' : ' ');
    cout << cnt << endl;


	return 0;
}

