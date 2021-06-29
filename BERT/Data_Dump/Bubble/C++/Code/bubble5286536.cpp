
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
int bubbleSort(vector<int> &A, int N) {
  int cnt = 0;
  // 2   flag = 1 // 逆の隣接要素が存在する
  bool flag = true;
  // 3   while flag
  while (flag) {
    // 4     flag = 0
    flag = false;
    // 5     for j が N-1 から 1 まで
    for (int j = N - 1; j > 0; j--) {
      // 6       if A[j] < A[j-1]
      if (A.at(j) < A.at(j - 1)) {
        // 7         A[j] と A[j-1] を交換
        int tmp = A.at(j);
        A.at(j) = A.at(j - 1);
        A.at(j - 1) = tmp;
        cnt++;
        // 8         flag = 1
        flag = true;
      }
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
  cout << bubbleSort(A, N) << endl;
  return 0;
}
