#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

ll bubbleSort(vector <ll> v, ll n) {
  ll flag = 1, res = 0;
  while (flag) {
    flag = 0;
    for (ll i = n-1; i > 0; i--) {
      if (v.at(i) < v.at(i-1)) {
        swap(v.at(i), v.at(i-1));
        res++;
        flag = 1;
      }
    }
  }
  rep(i, n) {
    if (i) cout << ' ' << v.at(i);
    else cout << v.at(i);
  }
  cout << endl;
  return res;
}

int main() {
  ll n; cin >> n;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  ll res = bubbleSort(v, n);
  cout << res << endl;
}
