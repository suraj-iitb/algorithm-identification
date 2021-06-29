#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef long long ll;
using s = string;
typedef string s;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define All(x) x.begin(), x.end();
#define SIZE(x) ll(x.size())
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange

int main () {
    ll N;
    cin >> N;

    ll A[N] = {};

    REP (i, N) {
        cin >> A[i];
        cout << A[i];
        if ( i != N-1) cout << " ";
    }
    cout << endl;

    FOR (i, 1, N-1) {
        ll j = i-1 , v = A[i];
        for (; j >= 0 && A[j] > v; j--) A[j+1] = A[j];
        A[j+1] = v;
        REP (j, N) {
            cout << A[j];
            if ( j != N-1 ) cout << " ";
        }
        cout << endl;
    }
}
