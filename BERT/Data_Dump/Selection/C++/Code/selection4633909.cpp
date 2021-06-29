#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << ' ';
    cout << A[i];
  }
  cout << endl;
}

void selectionSort(vector<int> A, int N) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    int minJ = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minJ]) {
        minJ = j;
      }
    }
    if (minJ != i) {
      int temp = A[i];
      A[i] = A[minJ];
      A[minJ] = temp;
      count++;
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
  selectionSort(A, N);
}
