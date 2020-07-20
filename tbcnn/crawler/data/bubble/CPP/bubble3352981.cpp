#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  int count = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = n-1; i > 0; i--) {
      if (a.at(i) < a.at(i-1)) {
        int b = a.at(i), c = a.at(i-1);
        a.at(i) = c;
        a.at(i-1) = b;
        count++;
        flag = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == n-1) cout << a.at(i) << endl;
    else cout << a.at(i) << ' ';
  }
  cout << count << endl;
}
