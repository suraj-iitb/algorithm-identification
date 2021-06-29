#include<iostream>
#include <stdio.h>
using namespace std;

void trace(int A[], int n) {
  int i;
  for(i=0; i<n; i++) {
    if (i>0) {
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
}

void InsertionSort(int A[], int n) {
  int i, j, v;

  for (i=0; i<n; i++) {
    v = A[i];
    j = i-1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, n);
  } 
}

int main() {
  int n;
  int A[1000];
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }
  InsertionSort(A, n);

  return 0;
}
