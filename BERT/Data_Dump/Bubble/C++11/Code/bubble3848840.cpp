#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int BubbleSort(vector<T> &a) {
  int swap_times = 0;
  int n = a.size();
  bool has_sorted = false;
  while (!has_sorted) {
    has_sorted = true;
    for (int i = n - 1; i >= 1; --i) {
      if (a[i-1] > a[i]) {
        swap(a[i], a[i-1]);
        ++swap_times;
        has_sorted = false;
      }
    }
  }
  return swap_times;
}

template <typename T>
void PrintVector(vector<T> &a) {
  int n = a.size();
  if (n <= 0) return;
  cout << a[0];
  for (int i = 1; i < n; ++i) {
    cout << ' ' << a[i];
  }
  cout << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = BubbleSort<int>(a);
  PrintVector<int>(a);
  cout << res << endl;
}
