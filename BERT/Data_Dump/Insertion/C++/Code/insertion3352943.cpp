#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  for (int i = 0; i < n; i++) {
    int x = a.at(i), j = i-1;
    while (j >= 0 && a.at(j) > x) {
      a.at(j+1) = a.at(j);
      j--;
    }
    a.at(j+1) = x;
    for (int i = 0; i < n; i++) {
      if (i == n-1) cout << a.at(i) << endl;
      else cout << a.at(i) << ' ';
    }
  }
}
