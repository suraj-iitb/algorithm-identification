#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>
#include <climits>
#include <queue>

using namespace std;

void sort(std::vector<int>& xs) {
  int swapCount = 0;
  for (int i = 0; i < xs.size(); ++i) {
    int m = i;
    for (int j = i + 1; j < xs.size(); ++j) {
      if (xs[j] < xs[m]) {
        m = j;
      }
    }
    if (i != m) {
      swap(xs[i], xs[m]);
      ++swapCount;
    }
  }

  for (int i = 0; i < xs.size(); ++i) {
    if (i != 0) cout << " ";
    cout << xs[i];
  }
  cout << endl;
  cout << swapCount << endl;
}

int main() {
  int n;
  cin >> n;
  std::vector<int> xs(n);
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
  }
  sort(xs);
}

