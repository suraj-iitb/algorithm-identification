#include <iostream>
#include <string>
#include <cstdio>

void print_array(int A[], int N) {
  
  for (int i=0; i < N; i++) {
    if (i > 0) printf(" ");

    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int N) {

  for (int i=1; i < N; i++) {
    int v = A[i];
    int j = i - 1;
  
    while (j>= 0 and A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
  A[j+1] = v;
  print_array(A, N);
  }
}

int main() {

  int N;
  int A[100];
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  print_array(A, N);
  insertionSort(A, N);

  return 0;
}
