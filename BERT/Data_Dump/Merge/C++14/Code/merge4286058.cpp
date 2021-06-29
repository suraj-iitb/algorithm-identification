#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll merge(ll a[], ll l, ll m, ll r){
    ll n1 = m - l, n2 = r - m;
    ll L[n1+1], R[n2+1];
    rep(i, n1) L[i] = a[l + i];
    rep(i, n2) R[i] = a[m + i];
    L[n1] = LLONG_MAX;
    R[n2] = LLONG_MAX;
    ll i = 0, j = 0;
    for(ll k = l; k < r; k++)
        (L[i] <= R[j]) ? a[k] = L[i++] : a[k] = R[j++];
    return r - l;
}

ll merge_sort(ll a[], ll l, ll r){
    ll cnt = 0;
    if(l + 1 < r){
        ll m = (l + r)/2;
        cnt += merge_sort(a, l, m);
        cnt += merge_sort(a, m, r);
        cnt += merge(a, l, m, r);
    }
    return cnt;
}

int main(){
    ll n; cin >> n;
    ll s[n]; rep(i, n) cin >> s[i];

    ll cnt = merge_sort(s, 0, n);
    rep(i, n) cout << s[i] << char((i < n-1) ? ' ' : '\n');
    cout << cnt << endl;

    return 0;
}

