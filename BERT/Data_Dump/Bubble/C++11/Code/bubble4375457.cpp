#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

void bubble_sort(deque<int> values, int n) {
  bool flag = true;
  int cnt = 0;

  while (flag) {
    flag = false;

    for (int i = n - 1; i >= 1; i--) {
      if (values[i] < values[i - 1]) {
        int tmp;

        tmp = values[i - 1];
        values[i - 1] = values[i];
        values[i] = tmp;

        flag = true;
        cnt++;
      }
    }
  }

  // print
  for (int i = 0; i < n - 1; i++) {
    cout << values[i] << " ";
  }
  cout << values[n - 1] << endl;

  cout << cnt << endl;
}

int main() {
  int n;
  deque<int> values;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    values.push_back(tmp);
  }

  bubble_sort(values, n);

  return 0;
}
