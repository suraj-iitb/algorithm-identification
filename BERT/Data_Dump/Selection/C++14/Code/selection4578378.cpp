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
  int N, cnt = 0;
  cin >> N;
  vector<int> A(N);
  for (size_t i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  for (size_t i = 0; i < N; i++) {
    auto minA = i;

    for (size_t j = i; j < N; j++) {
      if (A[minA] > A[j]) {
        minA = j;
      }
    }
    if (minA != i) {
      auto tmp = A[minA];
      A[minA] = A[i];
      A[i] = tmp;
      cnt++;
    }
  }

  printVec(A);
  cout << cnt << endl;
}
