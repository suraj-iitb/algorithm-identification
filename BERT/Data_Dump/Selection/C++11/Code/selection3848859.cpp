#include <iostream>
#include <vector>
using namespace std;

int SelectionSort(vector<int> &a) {
  int n = a.size(), min_j, swap_times = 0;
  for (int i = 0; i < n - 1; ++i) {
    min_j = i;
    for (int j = i + 1; j < n; ++j) { 
      if (a[j] < a[min_j]) {
        min_j = j;
      }
    }
    if (i != min_j) {
      swap(a[i], a[min_j]);
      ++swap_times;
    }
  }
  return swap_times;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = SelectionSort(a);
  cout << a[0];
  for (int i = 1; i < n; ++i) {
    cout << ' ' << a[i];
  }
  cout << endl;
  cout << res << endl;
}
