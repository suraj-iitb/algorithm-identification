#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  int j;
  int v;
  for (int i = 0; i < vec.size(); i++) {
    cin >> vec.at(i);
    if (i > 0) cout << " ";
    cout << vec.at(i);
  }
  cout << endl;
  for (int i = 1; i < n; i++) {
    v = vec.at(i);
    j = i - 1;
    while (j >= 0 && vec.at(j) > v) {
      vec.at(j + 1) = vec.at(j);
      j--;
    }
    vec.at(j + 1) = v;
    for (int i = 0; i < vec.size(); i++) {
      if (i > 0) cout << " ";
      cout << vec.at(i);
    }
    cout << endl;
  }
}

