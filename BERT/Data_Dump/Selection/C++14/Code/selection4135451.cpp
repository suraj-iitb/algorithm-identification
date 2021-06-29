#include <bits/stdc++.h>
using namespace std;

int selection_sort(int A[], int N) {
  int sw = 0;

  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A[minj] > A[j]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) sw++;
  }
  return sw;
}

int main() {
  int A[100];
  int N;
  int sw;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sw = selection_sort(A, N);

  for (int i = 0; i < N; i++) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", sw);
  return 0;
}
