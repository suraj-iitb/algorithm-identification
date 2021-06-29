#include <iostream>
using namespace std;

int main() {
  int n, tmp, index, count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // sort
  for (int i = 0; i < n - 1; ++i) {
    index = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[index]) {
        index = j;
      }
    }
    // swap
    tmp = a[i];
    a[i] = a[index];
    a[index] = tmp;
    if (index != i) count++;
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  }
  cout << count << '\n';
}

