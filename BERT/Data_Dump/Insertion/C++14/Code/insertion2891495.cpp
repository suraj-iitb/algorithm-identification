#include <bits/stdc++.h>
using namespace std;
void out(vector<int> a) {
  int n = a.size();
  for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
  cout << a[n - 1] << '\n';
}
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  out(a);
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 and a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    out(a);
  }
  return 0;
}
