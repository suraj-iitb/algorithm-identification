#include<stdio.h>

#define MAX 500000
#define INFTY 1000000000

int L[MAX/2+2], R[MAX/2+2];
int sum;

int main() {
  int A[MAX],n,i;

  scanf("%d",&n);
  sum = 0;
  for(i = 0 ; i < n ; i++) {
    scanf("%d",&A[i]);
    if(A[i] >= INFTY) {
      return 1;
    }
  }
  mergeSort(A,n,0,n);

  for(i = 0 ; i < n-1 ; i++) {
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",sum);
  return 0;
}

void merge(int A[], int n, int left, int mid, int right) {
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0 ; i < n1 ; i++) {
    L[i] = A[left + i];
  }
  for(i = 0 ; i < n2 ; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INFTY;
  i = j = 0;
  for(k = left ; k < right ; k++) {
    sum++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  int mid;

  if(left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

