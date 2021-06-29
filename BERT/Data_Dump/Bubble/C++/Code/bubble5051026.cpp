#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  
  bool flag = true;
  int start = 0;
  int cnt = 0;
  while (flag) {
    flag = false;
    for (int i = n-1; i > start; i--) {
      if (v.at(i) < v.at(i-1)) {
        swap(v.at(i), v.at(i-1));
        flag = true;
        cnt++;
      }
    }
    start++;
  }
  
  for (int i = 0; i < n; i++) {
    cout << v.at(i);
    if (i != n-1) cout << " ";
    else cout << endl;
  }
  
  cout << cnt << endl;
  
  return 0;
}
