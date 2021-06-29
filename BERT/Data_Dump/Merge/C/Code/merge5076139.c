#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, *s, c = 0;

void merge(int, int, int);
void mergeSort(int, int);

int main(){
  int i;

  scanf("%d", &n);
  s = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++) scanf("%d", &s[i]);

  mergeSort(0, n);

  for(i = 0; i < n; i++){
    printf("%d", s[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n%d\n", c);
  
  return 0;
}

void merge(int left, int mid, int right){
  int i, j, k, n1 = mid-left, n2 = right-mid;
  int L[n1+1], R[n2+1];
  for(i = 0; i < n1; i++) L[i] = s[left+i];
  for(i = 0; i < n2; i++) R[i] = s[mid+i];
  i = 0;
  j = 0;
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  for(k = left; k < right; k++){
    c++;
    if(L[i] <= R[j]){
      s[k] = L[i];
      i++;
    }
    else {
      s[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

