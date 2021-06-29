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

// バブルソート

int main () {
    ll N;
    cin >> N;
    ll A[N] = {};
    REP (i, N) cin >> A[i];
    ll cnt = 0;
    FORD (i, N, 1) {
        FOR (j, 1, i-1) {
            if (A[j-1] > A[j]) {
                ll tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                cnt++;
            } 
        }
    }
    REP (i, N) {
        cout << A[i];
        if (i != N-1) cout << " ";
    }
    cout << endl;

    cout << cnt << endl;
}
