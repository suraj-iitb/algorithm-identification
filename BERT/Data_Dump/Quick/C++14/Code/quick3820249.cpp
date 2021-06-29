#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

vll a;
string s;

ll partition(ll p, ll r){
    ll x = a[r];
    ll i = p-1;
    repr(j, p, r){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
            swap(s[i], s[j]);
        }
    }
    swap(a[i+1], a[r]);
    swap(s[i+1], s[r]);
    return i+1;
}

void quickSort(ll p, ll r){
    if(p < r){
        ll q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}

map<ll, string> mp;
map<ll, string> mp_sorted;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    rep(i, n){
        char c;
        cin >> c;
        s.push_back(c);
        ll e;
        cin >> e;
        a.push_back(e);
        mp[e].push_back(c);
    }
    quickSort(0, n-1);
    rep(i, n){
        mp_sorted[a[i]].push_back(s[i]);
    }
    bool f = 1;
    for(auto&& e: mp){
        if(e.second != mp_sorted[e.first]){
            f = 0;
        }
    }
    if(f) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    rep(i, n){
        cout << s[i] << " " << a[i] << endl;
    }
    return 0;
}
