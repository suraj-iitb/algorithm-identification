
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void insertionSort(vector<int> A, int N) {
  // N個の要素を含む0-オリジンの配列A
  // for i が 1 から N-1 まで
  for (int i = 1; i <= N; i++) {
    rep(k, N) {
      if (k != 0) {
        cout << " ";
      }
      cout << A.at(k);
    }
    cout << endl;
    if (i == N) break;
    // v = A[i]
    int v = A.at(i);
    // j = i - 1
    int j = i - 1;
    // while j >= 0 かつ A[j] > v
    while (j >= 0 && A.at(j) > v) {
      // A[j+1] = A[j]
      A.at(j + 1) = A.at(j);
      // j--
      j--;
      // A[j+1] = v
      A.at(j + 1) = v;
    }
  }
}
int main() {
  int N, tmp;
  cin >> N;
  vector<int> A;
  rep(i, N) {
    cin >> tmp;
    A.push_back(tmp);
  }
  insertionSort(A, N);
  return 0;
}
