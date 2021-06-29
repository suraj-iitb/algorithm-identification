#include <iostream>
#include <cstdio>
using namespace std;

void printList(int A[], int N) {
  for(int i=0; i<N; i++) {
    if(!i) {
      printf("%d", A[i]);
      continue;
    }
    printf(" %d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int N) {
  int v, j;
  for(int i=1; i<N; i++) {
    printList(A, N);
    v = A[i];
    j = i-1;
    while( j>=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  printList(A, N);
}

int main(void) {
  int N;
  int A[101];

  cin >> N;
  for(int i=0; i<N; i++) scanf("%d", &A[i]);

  insertionSort(A, N);

  return 0;
}
