#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> l(n);
  for (int i=0; i<n; i++){
    cin >> l.at(i);
  }

  bool flag = true;
  int ans = 0;
  while (flag) {
    flag = false;
    for (int i=n-1; i>0; i--){
      if (l.at(i-1) > l.at(i)) {
        swap(l.at(i-1), l.at(i));
        ans++;
        flag = true;
      }
    }
  }
  for (int i=0; i<n-1; i++){
    cout << l.at(i) << " ";
  }
  cout << l.at(n-1) << endl;
  cout << ans << endl;
}

