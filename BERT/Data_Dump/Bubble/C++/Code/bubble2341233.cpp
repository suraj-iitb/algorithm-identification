#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace {

std::string Join(const int* A, int n) {
  std::stringstream ss;
  if (n > 0)
    ss << A[0];
  for (int i = 1; i < n; ++i) {
    ss << " ";
    ss << A[i];
  }
  return ss.str();
}

inline void swap(int& a, int& b) {
  const int t = a;
  a = b;
  b = t;
}

int BubbleSort(int* A, int n) {
  int nswap = 0;
  bool flag = true;
  while (flag) {
    flag = false;

    for (int j = n - 1; j > 0; --j) {
      if (A[j - 1] <= A[j])
        continue;
      swap(A[j - 1], A[j]);
      ++nswap;
      flag = true;
    }
  }
  return nswap;
}

}  // namespace

int main() {
  int n;
  int A[100];

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> A[i];

  const int ret = BubbleSort(A, n);
  cout << Join(A, n) << endl;
  cout << ret << endl;

  return 0;
}
