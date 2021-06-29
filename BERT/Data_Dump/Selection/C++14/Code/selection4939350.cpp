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

// 選択ソート

int main () {
    ll N;
    cin >> N;
    ll A[N] = {};
    REP (i, N) cin >> A[i];
    ll  cnt = 0;
    REP (i, N-1) {
        ll min = i;
        FOR (j, i, N) if (A[j] < A[min]) min = j;
        if (min != i){
            ll tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
            cnt++;
        }
    }
    REP (i, N-1) cout << A[i] << " ";
    cout << A[N-1] << endl;
    cout << cnt << endl;

}
