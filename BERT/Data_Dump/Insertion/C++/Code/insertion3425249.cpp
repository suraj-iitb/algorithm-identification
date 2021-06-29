#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {

    if (i == 0) {
      for (int k = 0; k < N; k++) {
        if (k == N - 1) {
          cout << A[k] << endl;
        } else {
          cout << A[k] << ' ';
        }
      }
      continue;
    }

    int inum = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > inum) {
      int jnum = A[j];
      A[j + 1] = jnum;
      A[j] = inum;
      j -= 1;
    }
    for (int l = 0; l < N; l++) {
      if (l == N - 1) {
        cout << A[l] << endl;
      } else {
        cout << A[l] << ' ';
      }
    }
  }
}

