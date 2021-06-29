#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

const ll MAX = 5*(ll)pow(10, 5) + 1;
vector <ll> v(MAX, INF);
ll res = 0;

void merge(ll left, ll mid, ll right) {
  ll n1 = mid-left, n2 = right-mid;
  vector <ll> L(n1+1), R(n2+1);
  rep(i, n1) L.at(i) = v.at(left+i);
  rep(i, n2) R.at(i) = v.at(mid+i);
  L.at(n1) = INF; R.at(n2) = INF;
  ll i = 0, j = 0;
  for (ll k = left; k < right; k++) {
    res++;
    if (L.at(i) <= R.at(j)) {
      v.at(k) = L.at(i);
      i++;
    } else {
      v.at(k) = R.at(j);
      j++;
    }
  }
  return;
}

void mergeSort(ll left, ll right) {
  if (left+1 < right) {
    ll mid = (left+right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
  return;
}

int main() {
  ll n; cin >> n;
  rep(i, n) cin >> v.at(i);
  mergeSort(0, n);
  rep(i, n) {
    if (i) cout << ' ';
    cout << v.at(i);
  }
  cout << endl;
  cout << res << endl;
}
