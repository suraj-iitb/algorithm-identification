#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

void print_current(deque<int> arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    cout << arr[i] << ' ';
  }
  cout << arr[n - 1] << endl;
}

void insertion_sort(deque<int> arr, int n) {
  print_current(arr, n);

  for (int i = 1; i < n; i++) {
    int val = arr[i];
    int j;

    for (j = i - 1; j >= 0 && arr[j] > val; j--) {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = val;

    print_current(arr, n);
  }
}

int main() {
  int n;
  deque<int> arr;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }

  insertion_sort(arr, n);

  return 0;
}
