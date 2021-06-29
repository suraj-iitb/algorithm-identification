#include <bits/stdc++.h>
using namespace std;

#define rep(i, u) for (int i = 0; i < u; i++)

using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  int a[100] = {};
  cin >> n;
  rep(i, n) cin >> a[i];
  bool flag = true;
  int ans = 0;
  while (flag) {
    flag = false;
    rep(i, n - 1) {
      if (a[i + 1] < a[i]) {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        flag = true;
        ans++;
      }
    }
  }
  rep(i, n) {
    cout << a[i];
    if (i != n - 1) cout << ' ';
    else cout << endl;
  }
  cout << ans << endl;
  return 0;
}

