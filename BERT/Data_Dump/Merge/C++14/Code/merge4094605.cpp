#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> a;

void solve(int l, int r);

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  solve(0, n);
  for(int i = 0; i < n; ++i) {
    if(i != 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}

void solve(int l, int r) {
  if(r - l <= 1) return;
  solve(l, (l + r) / 2);
  solve((l + r) / 2, r);
  vector<int> dummy(r - l, 0);
  int lid = l, rid = (l + r) / 2, half = (l + r) / 2;
  for(int i = 0; i < r - l; ++i) {
    ++ans;
    if(lid < half && rid < r) {
      if(a[lid] < a[rid])
        dummy[i] = a[lid++];
      else
        dummy[i] = a[rid++];
    }
    else if(lid < half)
      dummy[i] = a[lid++];
    else
      dummy[i] = a[rid++];
  }
  for(int i = 0; i < r - l; ++i) a[l + i] = dummy[i];
}
