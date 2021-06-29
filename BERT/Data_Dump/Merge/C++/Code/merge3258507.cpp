#include <stdio.h>
#include <limits>
#include <iostream>
using namespace std;

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1];
  int R[n2+1];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1]=numeric_limits<int>::max();
  R[n2]=numeric_limits<int>::max();
  int i = 0, j = 0;
  for (int k = left; k < right;k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  mergeSort(S, 0, n);
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", S[i]);
  }
  printf("\n");
  printf("%d\n", cnt);
  return 0;
}

