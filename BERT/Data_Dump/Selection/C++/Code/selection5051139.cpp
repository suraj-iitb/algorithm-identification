#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i+1; j < n; j++) {
      if (v.at(j) < v.at(minj)) minj = j;
    }
    swap(v.at(i), v.at(minj));
    if (i != minj) cnt++;
  }
  
  for (int i = 0; i < n; i++) {
    cout << v.at(i);
    if (i != n-1) cout << " ";
    else cout << endl;
  }
  cout << cnt << endl;
  
  return 0;
}
