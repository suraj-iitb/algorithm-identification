#include <bits/stdc++.h>
using namespace std;
int n, a[101];

void print() {
  cout << a[0];
  for (int i = 1; i < n; i++) {
    cout << " " << a[i];
  }
  cout << "\n";
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  print();
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    print();
  }
}
