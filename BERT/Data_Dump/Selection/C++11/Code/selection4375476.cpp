#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

void selection_sort(deque<int> values, int n) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int minInd = i;

    for (int j = i; j < n; j++) {
      if (values[j] < values[minInd]) {
        minInd = j;
      }
    }

    if (minInd == i) continue;

    int tmp;

    tmp = values[i];
    values[i] = values[minInd];
    values[minInd] = tmp;

    cnt++;
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

  selection_sort(values, n);

  return 0;
}
