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

int bubbleSort(int A[], int n) {
  int i = 0;
  int flag = 1;
  int count = 0;
  while (flag) {
    flag = 0;
    for (int j=n-1; j>=i+1; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        count += 1;
        flag = 1;
      }
    }
    i += 1;
  }
  return count;
}

int main() {
  int n;
  int A[100];
  int c;

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &A[i]);
  }
  c = bubbleSort(A, n);
  trace(A, n);
  printf("%d\n", c);
}
