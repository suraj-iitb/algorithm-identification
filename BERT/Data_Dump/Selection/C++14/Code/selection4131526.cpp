#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> l(n);
  for (int i=0; i<n; i++) {cin >> l.at(i);}
  int count = 0;

  for (int i=0; i<n-1; i++) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (l.at(minj) > l.at(j)) {
        minj = j;
      }
    }
    if (minj != i)  count++;
    swap(l.at(minj), l.at(i));
  }
  for (int i=0; i<n-1; i++) {
    cout << l.at(i) << " ";
  }
  cout << l.at(n-1) << endl;
  cout << count << endl;
}

