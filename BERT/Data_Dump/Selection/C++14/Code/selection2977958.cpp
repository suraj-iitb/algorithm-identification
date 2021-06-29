#include <bits/stdc++.h>
using namespace std;

int selection(int n, vector<int> &v) {
  int cnt = 0;
  int minj;
  for (int i = 0; i < n; i++) {
    minj = i;
    for (int j = i; j < n; j++) {
      if (v.at(j) < v.at(minj))
      minj = j;
    }
    if (v.at(i) != v.at(minj)) {
      swap(v.at(i), v.at(minj));
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }

  int ans = selection(n, v);
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
    cout << v.at(i) << endl;
    else
    cout << v.at(i) << " ";
  }
  cout << ans << endl;
}

