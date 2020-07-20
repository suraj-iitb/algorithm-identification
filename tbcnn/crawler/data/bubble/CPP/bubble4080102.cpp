#include<bits/stdc++.h>
using namespace std;

void printArray(int A[], int N) {
  for (int i=0; i<N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

void bubbleSort(int A[], int N) {
  int flag = 1;
  int counter = 0;
  while (flag) {
    flag = 0;
    for (int j=N-1; j>0; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        flag = 1;
        counter += 1;
      }
    }
  }
  printArray(A, N);
  cout << counter << endl;
}

int main() {
  int N;
  cin >> N;
  int A[N];

  for (int i=0; i<N; i++) cin >> A[i];
  bubbleSort(A, N);
}
