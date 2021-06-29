#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  bool f = true;
  while (f) {
    f = false;
    for (int j = n - 1; j >= 1; j--) {
      if (a[j] < a[j - 1]) {
        res++;
        swap(a[j], a[j - 1]);
        f = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == n - 1) break;
    cout << ' ';
  }
  cout << '\n' << res << '\n';
  return 0;
}
