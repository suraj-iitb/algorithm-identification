#include<stdio.h>

void marge(int *, int, int, int);
void mergeSort(int *, int, int);
int count=0;

int main(){
  int i, j, n, S[500000];

  scanf("%d", &n);
  if(n <= 500000){
    for(i = 0; i < n; i++){
      scanf("%d", &S[i]);
    }

    mergeSort(&S[0], 0, n);
    
    for(i = 0; i < n; i++){
      if(i != n-1)
	printf("%d ", S[i]);
      else
	printf("%d\n", S[i]);
    }
    printf("%d\n", count);
  }
  return 0;
}

void merge(int *A, int left, int mid, int right){
  int L[250001], R[250001], i, j, k, n1, n2;

  n1 = mid - left;
  n2 = right - mid;
  if(n1 == 0 || n2 == 0) return;
  //  L[0...n1], R[0...n2] を生成
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;
  for (k = left; k < right; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }else{
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}

void mergeSort(int *A, int left, int right){
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(&A[0], left, mid);
    mergeSort(&A[0], mid, right);
    merge(&A[0], left, mid, right);
  }
  return;
}

