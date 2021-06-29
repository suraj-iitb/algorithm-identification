#include <bits/stdc++.h>
using namespace std;

int bubble(int n, vector<int> &v) {
  int cnt = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = n - 1; i >= 1; i--) {
      if (v.at(i) < v.at(i - 1)) {
        swap(v.at(i), v.at(i - 1));
        cnt++;
        flag = true;
      }
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

  int ans = bubble(n, v);
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
    cout << v.at(i) << endl;
    else
    cout << v.at(i) << " ";
  }
  cout << ans << endl;
}

