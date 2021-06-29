#include <iostream>
using namespace std;

void print_list(int a[], int n) {
  cout << a[0];
  for (int i = 1; i < n; ++i) {
    cout << ' ' << a[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, key;
  cin >> n;
  int a[105];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  print_list(a, n);
  for (int i = 1; i < n; ++i) {
    key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j+1] = a[j];
      --j;
    }
    a[j+1] = key;
    print_list(a, n);
  }
  return 0;
}
