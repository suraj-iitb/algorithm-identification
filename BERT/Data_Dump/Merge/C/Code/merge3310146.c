#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000
int L[MAX/2+2],R[MAX/2+2];
int cnt = 0;

void merge(int A[],int left,int mid,int right){
  int i,j,k,n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
  }
  for(j = 0; j < n2;j++){
    R[j] = A[mid + j];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k <= right-1;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int i,mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int A[MAX],n,i;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i < n-1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
  
  

