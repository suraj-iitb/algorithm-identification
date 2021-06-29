#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    swap(a[i], a[minj]);
    if (i != minj) {
      count++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i<n-1) cout << a[i] << " ";
    else cout << a[i] << endl;
  }

  cout << count << endl;
}