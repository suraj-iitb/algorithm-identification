#include <iostream>
using namespace std;

int main() {
  int n, v, j;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cout << a[i] << ((i == n - 1) ? "\n" : " ");
  }
  for (int i = 1; i < n; ++i) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    for (int k = 0; k < n; ++k) {
      cout << a[k] << ((k == n - 1) ? "\n" : " ");
    }
  }
}

