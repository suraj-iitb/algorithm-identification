#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int sw = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(A[i], A[minj]);
      sw++;
    }
  }
  trace(A, N);
  cout << sw << endl;
}

