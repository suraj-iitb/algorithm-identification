#include <stdio.h>
#include <math.h>
int merge(int *,int,int,int);
int mergeSort(int *,int,int);
int n,i,j,count=0;

int main(){
  int S[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i==n-1) break;
    else printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}

int merge(int *A,int left,int mid,int right){
  int n1,n2,k,L[500000],R[500000];
  n1 = mid - left;
  n2 = right - mid;
  for (i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for (i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
    L[n1] = INFINITY;
    R[n2] = INFINITY;
    i = 0;
    j = 0;
  for(k=left;k<right;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}

int mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  return 0;
}
