#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<int> v;

int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  for(int i = 0; i < n; ++i)
    for(int j = 1; j < n; ++j)
      if(v[j - 1] > v[j]) {
        swap(v[j - 1], v[j]);
        ++cnt;
      }

  for(int i = 0; i < n; ++i) {
    if(i != 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}
