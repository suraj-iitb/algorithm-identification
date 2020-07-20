#include <bits/stdc++.h>
using namespace std;

// N 個の要素を含む 0-オリジンの配列 A
int bubbleSort(vector<int> &A, int N) {
  bool flag = true; // 逆の隣接要素が存在する

  int i = 0;

  while (flag) {
    flag = false;

    for (int j = 1; j < N; j++) {
      if (A.at(j) < A.at(j - 1)) {
        swap(A.at(j), A.at(j - 1));
        flag = true;
        i++;
      }
    }
  }

  return i;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) cin >> A.at(i);

  int ans = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i != N - 1) {
      cout << A.at(i) << " ";
    } else {
      cout << A.at(i) << endl;
    }
  }

  cout << ans << endl;
}

