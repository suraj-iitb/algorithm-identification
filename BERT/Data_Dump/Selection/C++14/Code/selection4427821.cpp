#include <iostream>
using namespace std;

int selection_sort(int a[], int n) {
  int swaps = 0;
  for (int i = 0; i < n - 1; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    swap(a[i], a[minj]);
    if (i != minj) {
      ++swaps;
    }
  }
  return swaps;
}

int main() {
  int a[100], n, i, swaps;
    cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  swaps = selection_sort(a, n);

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << endl;
  cout << swaps << endl;

  return 0;
}

