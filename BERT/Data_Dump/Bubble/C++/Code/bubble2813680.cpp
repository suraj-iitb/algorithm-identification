#include <iostream>
using namespace std;

int main() {
  int n, tmp, count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; i < j; --j) {
      if (a[j] < a[j - 1]) {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
        count++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  }
  cout << count << endl;
}

