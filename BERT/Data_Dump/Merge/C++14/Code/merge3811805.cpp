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
inline ll powint(ll x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

ll ans = 0;

void merge(vll& A, ll left, ll mid, ll right){
    ll n1 = mid-left;
    ll n2 = right-mid;
    vll L(n1+1), R(n2+1);
    rep(i, n1){
        L[i] = A[left+i];
    }
    rep(i, n2){
        R[i] = A[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    ll i = 0;
    ll j = 0;
    repr(k, left, right){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        ans++;
    }
}

void mergeSort(vll& A, ll left, ll right){
    if(left+1 < right){
        ll mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    rep(i, n){
        cout << a[i] << (i+1 == n ? "\n" : " ");
    }
    cout << ans << endl;
    return 0;
}
