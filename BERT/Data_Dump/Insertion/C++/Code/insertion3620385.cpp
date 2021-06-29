#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void print(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i != N - 1)
      printf("%d ", A[i]);
    else
      printf("%d\n", A[i]);
  }
}

void insertionSort(int A[], int N) {
  int i, j;
  for (i = 1; i < N; i++) {
    int v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    print(A, N);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  int A[N];
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  print(A, N);

  insertionSort(A, N);

  return 0;
}

