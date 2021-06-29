#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data(n);
  for (int i = 0; i < n; i++) {
      cin >> data.at(i);
      cout << data[i];
      if (i != n - 1) {
          cout << " ";
      }
  }
  cout << endl;

  for (int i = 1; i < n; i++) {
      int v = data[i];
      int j = i - 1;
      while(j >= 0 && data[j] > v) {
          data[j + 1] = data[j];
          j--;
      }
      data[j + 1] = v;

    for (int k = 0; k < n; k++) {
      cout << data[k];
      if (k != n - 1) {
          cout << " ";
      }
    }
    cout << endl;
  }
}
