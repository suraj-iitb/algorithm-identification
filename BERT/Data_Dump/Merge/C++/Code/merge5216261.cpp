#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
int cnt;
int L[MAX/2 + 2], R[MAX/2 +2];
void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for(int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for(int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = 1410065407;
  R[n2] = 1410065407;
  int i = 0, j = 0;
  for(int k = left; k < right; k++){
    cnt++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  if(left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}


int main() {
  int n;
  cnt = 0;
 scanf("%d", &n);
  int A[MAX];
  
  for(int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  mergeSort(A, n, 0, n);
  for(int i = 0; i < n; i++) {
    if(i < n-1) {
    printf("%d ", A[i]);
    }
    else{
      printf("%d", A[i]);
    }
  }
  printf("\n");
  printf("%d\n", cnt);
  
  
  return 0;
}