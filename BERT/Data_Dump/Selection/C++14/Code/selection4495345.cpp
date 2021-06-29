#include <bits/stdc++.h>
using namespace std;
int a[100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(a[i], a[minj]);
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (i ? " " : "") << a[i];
  }
  cout << "\n" << cnt << "\n";
}
