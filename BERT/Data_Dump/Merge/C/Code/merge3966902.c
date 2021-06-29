#include<stdio.h>

#define LIMIT 500000
#define INFTY 1000000001

int S[LIMIT];
int L[LIMIT/2+2], R[LIMIT/2+2];
int count = 0;

void merge(int A[], int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY; R[n2] = INFTY;

  i = 0; j = 0;
  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i, n;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(S, 0, n);

  for(i = 0; i < n; i++){
    if(i == n-1){
      printf("%d\n", S[i]);
    }else{
      printf("%d ", S[i]);
    }
  }

  printf("%d\n", count);

  return 0;
}

