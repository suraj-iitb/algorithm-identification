#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    if (i == vec.size() - 1) {
      cout << vec[i] << endl;
    } else {
      cout << vec[i] << " ";
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (size_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  printVec(A);

  for (size_t i = 1; i < N; i++) {
    for (size_t j = i; 0 < j; j--) {
      if (A[j - 1] > A[j]) {
        auto tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
      } else {
        break;
      }
    }
    printVec(A);
  }
}
