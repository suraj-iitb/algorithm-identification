#include <stdio.h>

int count = 0;

void merge(int *a, int left, int mid, int right){
  int i, j, k;
  int n1, n2;

  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1], R[n2+1];

  for(i = 0; i < n1; i++)
    L[i] = a[left + i];
  for(i = 0; i < n2; i++)
    R[i] = a[mid + i];
  L[n1] = 1000000001;
  R[n2] = 1000000001;

  i = j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      a[k] = L[i];
      i++;
    } else{
      a[k] = R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int *a, int left, int right){
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){

  int i, n, left, mid, right;

  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  mergeSort(a, 0, n);
  
  for(i = 0; i < n-1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", count);
  return 0;
}
