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
  int ans = 0;
  rep(i, n) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (a[i] != a[minj]) ans++;
    int tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
  }
  rep(i, n) {
    cout << a[i];
    if (i != n - 1) cout << ' ';
    else cout << endl;
  }
  cout << ans << endl;
  return 0;
}

