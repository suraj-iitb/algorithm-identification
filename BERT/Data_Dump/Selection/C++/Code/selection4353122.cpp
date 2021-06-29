#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define fin(ans) cout << (ans) << endl;
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q.r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef long long lli;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

//実行部
void Main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vll a(n);
    rep(i, n) cin >> a[i];
    for(ll i = 0;i < n;i++)
    {
        ll minj = i;
        for(ll j = i;j < n;j++)
        {
            if(a[j] < a[minj])
            {
                minj = j;
                
            }
        }
        if(i != minj)
        {
            swap(a[i], a[minj]);
            ans++;
        }
    }
    for (ll i = 0; i < a.size() - 1; i++)
        cout << a[i] << " ";
    cout << a[a.size() - 1] << endl;
    fin(ans) return;
}

//前処理
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20); //高精度少数表示
    Main();
    return 0;
}

