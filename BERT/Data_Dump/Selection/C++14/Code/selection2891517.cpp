#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    res += i != minj;
    swap(a[i], a[minj]);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == n - 1) break;
    cout << ' ';
  }
  cout << '\n' << res << '\n';
  return 0;
}
