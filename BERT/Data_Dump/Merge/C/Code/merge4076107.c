#include <stdio.h>
#include <math.h>
#define N 500000

int cnt = 0;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(){
  int i,n,A[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i = 0; i < n-1 ; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],cnt);
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,L[N],R[N],k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = 999999999;
  R[n2] = 999999999;
  i = 0;
  j = 0;
  for(k = left; k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      cnt++;
    }
    else {
      A[k] = R[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

