#include <iostream>
using namespace std;

int main() {
  int a[100], n, i, j, t, c;

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  c = 0;
  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        t = a[j];
        a[j] = a[j - 1];
        a[j - 1] = t;

        c++;
      }
    }
  }

  for (i = 0; i < n; i++) {
    cout << a[i];
    if (i != n - 1) {
      cout << ' ';
    }
  }

  cout << endl << c << endl;

  return 0;
}
