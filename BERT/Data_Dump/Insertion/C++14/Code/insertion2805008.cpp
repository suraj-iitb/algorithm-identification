#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>

using namespace std;

void print(const std::vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void insertionSort(std::vector<int>& A) {
  print(A);
  for (int i = 1; i < A.size(); ++i) {
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      --j;

    }
    A[j + 1] = v;
    print(A);
  }
}

int main() {
  int count;
  std::vector<int> A;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    int v;
    cin >> v;
    A.push_back(v);
  }
  insertionSort(A);
}

