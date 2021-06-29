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

void InsertionSort(int* A, int n) {
  cout << Join(A, n) << endl;
  for (int i = 1; i < n; ++i) {
    const int v = A[i];
    int j = i - 1;
    for (; j >= 0 && A[j] > v; --j) {
      A[j + 1] = A[j];
    }
    A[j + 1] = v;

    cout << Join(A, n) << endl;
  }
}

}  // namespace

int main() {
  int A[100];
  int n;

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  InsertionSort(A, n);
  return 0;
}
