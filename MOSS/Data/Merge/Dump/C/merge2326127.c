#include<stdio.h>
#include<math.h>
#define INFINITY 1000000001
int merge(int*,int,int,int);
int mergeSort(int*,int,int);
int count=0;

int main(){
  int a,i,n;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  count=mergeSort(S,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",count);
  return 0;
}

int merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1], R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
      }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k = left;k< right;k++){
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
  return count;
}
int mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  return count;
}
