//マージソート
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *,int ,int ,int);
void mergeSort(int *,int, int);

int count=0;
int main() {
  int i,j;
  int *S;
  int n;
  int left=0,mid,right;

  scanf("%d",&n);
  S = (int *)malloc((n+1) * sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  right = n;
  mergeSort(S,left,right);

  for(i=0;i<n-1;i++) {
    printf("%d ",S[i]);
  }
  printf("%d\n%d\n",S[n-1],count);
  
  return 0;
}

void merge(int *A,int left,int mid,int right) {
  int n1,n2;
  int *L,*R;
  int i,j;
  int k;
  n1 = mid-left;
  n2 = right - mid;
  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  for(i=0;i<n1;i++) {
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++) {
    R[i] = A[mid+i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i=j=0;
  for(k=left;k<right;k++) {
    count++;
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

void mergeSort(int *A,int left,int right) {
  int mid;
  if(left+1 < right) {
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
    
  }
}

