#include <iostream>
using namespace std;

int bubble_sort(int a[], int n) {
  int swaps = 0;
  bool swap_flag = 1;

  for (int i = 0; swap_flag; ++i) {
    swap_flag = 0;
    for (int j = n - 1; j >= i + 1; --j) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        swap_flag = 1;
        swaps++;
      }
    }
  }
  return swaps;
}

int main() {
  int a[100], n, swaps;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  swaps = bubble_sort(a, n);

  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << endl;
  cout << swaps << endl;

  return 0;
}

