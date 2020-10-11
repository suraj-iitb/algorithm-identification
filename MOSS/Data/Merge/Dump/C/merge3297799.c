#include <stdio.h>
#include <stdlib.h>
#define INFTY 2147483647

int mergeSort(int *,int,int);
int merge(int *,int,int,int);

int main(){
  int i,n,*S,count;

  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));
  for(i = 0;i < n;i++) scanf("%d",&S[i]);

  count = mergeSort(S,0,n);
  for(i = 0;i < n;i++){
    printf("%d",S[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n%d\n",count);
  
  free(S);
  return 0;
}

int merge(int *A,int left,int mid,int right){
  int *L,*R,i,j,k,n1,n2;
  static int count;
  n1 = mid - left;
  n2 = right - mid;
  // L[0...n1], R[0...n2] を生成
  L = (int *)malloc((n1 + 1) * sizeof(int));
  R = (int *)malloc((n2 + 1)* sizeof(int));
  for(i = 0;i < n1;i++) L[i] = A[left + i];
  for(i = 0;i < n2;i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
  return count;
}

int mergeSort(int *A,int left,int right){
  int count,mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    count = merge(A, left, mid, right);
  }
  return count;
}

