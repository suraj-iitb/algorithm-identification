#include <stdio.h>
#define MAX 500000
#define SEN 2000000000
 
int L[250002], R[250002],count = 0, A[MAX],n;

void merge(int left, int mid, int right) {
  int n1,n2,i,j,k;
 
  n1 = mid - left;
  n2 = right - mid;
 
  for(i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
 
  for(i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = SEN;
  R[n2] = SEN;
 
  i = 0;
  j = 0;
for(k = left; k < right; k++) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
      count++;
    }
    else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
}


void mergeSort(int left, int right) {
  int mid;
  if(left+1 < right) {
    mid =(left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
 
int main()
{
  int i;
 
  scanf("%d",&n);
 
  for(i = 0; i < n; i++) {
    scanf("%d",&A[i]);
  }
  mergeSort(0, n);
  for(i = 0; i < n - 1 ; i++) {
    printf("%d ",A[i]);
  }
  printf("%d", A[n - 1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}
