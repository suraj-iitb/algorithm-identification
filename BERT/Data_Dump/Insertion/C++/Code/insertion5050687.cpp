#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  
  for (int i = 0; i < n; i++) {
    int val = v.at(i);
  	int j = i - 1;
  	while (j >= 0 && v.at(j) > val) {
      v.at(j + 1) = v.at(j);
      j--;
    }
    v.at(j + 1) = val;
    for (int k = 0; k < n; k++) {
      cout << v.at(k);
      if (k != n - 1) cout << " ";
      else cout << endl;
    }
  }
  
  return 0;
}
