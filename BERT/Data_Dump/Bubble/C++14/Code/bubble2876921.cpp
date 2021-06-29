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

void bubbleSort(std::vector<int>& xs) {
  int swapCount = 0;
  for (int i = 0; i < xs.size(); ++i) {
    for (int j = xs.size() - 1; j > i; --j) {
      if (xs[j] < xs[j - 1]) {
        swap(xs[j], xs[j - 1]);
        ++swapCount;
      }
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
  bubbleSort(xs);
}

