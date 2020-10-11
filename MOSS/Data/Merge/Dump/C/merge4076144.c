#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int c=0;
void merge(int *A,int left,int mid,int right){
  int n1,n2,i,k,j,L[500000],R[500000];
  n1 = mid - left;
  n2 = right - mid;
  /*L=(int *)malloc(n1 * sizeof(int));
    R=(int *)malloc(n2 * sizeof(int));*/
  for(i=0;i<=n1-1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = 2147483647;
  R[n2] = 2147483647;
  i = 0;
  j = 0;
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i = i + 1;
    }
    else{
      A[k]=R[j];
      j = j + 1;
    }
    c++;
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
      }
}



int main(){
  int i,n,S[500000],left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    if(i!=n-1){
    printf("%d ",S[i]);
    }
    else{
      printf("%d\n",S[i]);
    }
    
  }
    printf("%d\n",c);
  return 0;
}

