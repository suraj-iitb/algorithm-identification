#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &A, int N) {
  int sw = 0;
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int sw = bubbleSort(A, N);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << ' ';
    }
  }
  cout << sw << endl;
};

