#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << ' ';
    cout << A[i];
  }
  cout << endl;
}

void bubbleSort(vector<int> A, int N) {
  int flag = 1;
  int count = 0;
  while (flag) {
    flag = 0;
    for (int i = 1; i < N; i++) {
      if (A[i-1] > A[i]) {
        int temp = A[i];
        A[i] = A[i-1];
        A[i-1] = temp;
        flag = 1;
        count++;
      }
    }
  }
  trace(A, N);
  cout << count << endl;
}
  
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  bubbleSort(A, N);
}

