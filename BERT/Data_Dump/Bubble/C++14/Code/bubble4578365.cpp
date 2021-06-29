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
    for (size_t j = N - 1; i < j; j--) {
      if (A[j - 1] > A[j]) {
        auto tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        cnt += 1;
      }
    }
  }

  printVec(A);
  cout << cnt << endl;
}
