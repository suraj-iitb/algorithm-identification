#include<stdio.h>
#include<math.h>

int A[500000], compare;

void merge(int left, int mid, int right){
  int n1 = mid - left, n2 = right - mid, L[n1 + 1], R[n2 + 1], i, j, k;
  for(i=0;i<n1;i++)
    L[i] = A[left + i];
  for(i=0;i<n2;i++)
    R[i] = A[mid + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  compare++;
  }
}

void mergeSort(int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(void){
  int n, i;
  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", &A[i]);
  mergeSort(0, n);
  for(i=0;i<n-1;i++)
    printf("%d ", A[i]);
  printf("%d\n%d\n", A[n-1], compare);
  return 0;
}
