#include<stdio.h>

#define INFTY 1000000001

int count=0,n;
int main(){
  int i,left,right;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  left=0;
  right=n;
  mergeSort(S,left,right);
  for(i=0;i<n;i++){
    if(i<n-1)
      printf("%d ",S[i]);
      else printf("%d\n",S[i]);
    }
  printf("%d\n",count);
  return 0;
}

merge(int A[],int left,int mid,int right){
  int k,n1,n2,i,j;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1], R[n2];
  for(i = 0;i<=n1-1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i<=n2-1;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k<=right-1;k++){
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
}
mergeSort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
    //count++;
  }
}

