#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define str(s) #s
using namespace std;
using ll = long long;

void counting_sort(ll a[], ll b[], ll k, ll n){
    ll c[k+1];
    memset(c, 0, (k+1)*sizeof(ll));
    rep(i, 0, n) c[a[i]]++;
    rep(i, 1, k+1) c[i] += c[i-1];
    rep(i, 0, n) b[--c[a[i]]] = a[i];
    return;
}

int main(){
    ll n; cin >> n;
    ll a[n]; rep(i, 0, n) cin >> a[i];
    ll b[n];

    counting_sort(a, b, 10000, n);
    rep(i, 0, n) cout << b[i] << char((i == n-1) ? '\n' : ' ');

    return 0;
}

