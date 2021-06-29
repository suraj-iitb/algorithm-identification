
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 1 selectionSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
int selectionSort(vector<int> &A, int N) {
  bool isSwaped = false;
  int cnt = 0, minj;
  //   for i が 0 から N-1 まで
  rep(i, N) {
    //     minj = i
    minj = i;
    //     for j が i から N-1 まで
    isSwaped = false;
    for (int j = i; j < N; j++) {
      //       if A[j] < A[minj]
      if (A.at(j) < A.at(minj)) {
        //         minj = j
        minj = j;
        isSwaped = true;
      }
    }
    //     A[i] と A[minj] を交換
    if (isSwaped) {
      swap(A.at(i), A.at(minj));
      cnt++;
    }
  }
  rep(i, N) {
    if (i != 0) {
      cout << " ";
    }
    cout << A.at(i);
  }
  cout << endl;
  return cnt;
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) { cin >> A.at(i); }
  cout << selectionSort(A, N) << endl;
  return 0;
}
