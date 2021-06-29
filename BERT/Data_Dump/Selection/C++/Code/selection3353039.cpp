#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  int count = 0;
  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i; j < n; j++) {
      if (a.at(j) < a.at(mini)) mini = j;
    }
    if (mini != i) {
      int b = a.at(i), c = a.at(mini);
      a.at(i) = c;
      a.at(mini) = b;
      count++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == n-1) cout << a.at(i) << endl;
    else cout << a.at(i) << ' ';
  }
  cout << count << endl;
}
