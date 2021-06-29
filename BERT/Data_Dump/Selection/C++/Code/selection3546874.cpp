#include<iostream>
#include<stdio.h>
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

int selectionSort(int A[], int n) {
  int minj = 0;
  int count = 0;
  for (int i=0; i<n-1; i++) {
    minj = i;
    for (int j=i; j<n; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) {
      count += 1;
    }
  }
  return count;
}

int main() {
  int n=0;
  int A[100];
  int c = 0;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }

  c = selectionSort(A, n);
  trace(A, n);
  printf("%d\n", c);
}
