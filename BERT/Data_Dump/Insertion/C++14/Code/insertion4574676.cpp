#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void insertion(ll a[], ll n){
    for (ll i = 0; i < n;i++){
        ll v = a[i];
        ll j = i - 1;
        while(j>=0&&a[j]>v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (ll i = 0;i<n-1;i++){
            cout << a[i] << " ";
        }
        cout << a[n - 1] << endl;
    }
}
int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    insertion(a, n);
}

