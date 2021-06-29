#include <stdio.h>
#include <math.h>

int count = 0;

void merge(int A[],int left,int mid,int right){
  int n1 = mid - left,n2 = right - mid;
  int L[n1],R[n2];
  int i,j,k;

  for(i=0;i<=n1-1;i++)L[i] = A[left + i];
  for(i=0;i<=n2-1;i++)R[i] = A[mid + i];

  L[n1] = 10000000000;
  R[n2] = 10000000000;
  i = 0;j = 0;

  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int n,S[10000000],i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++)printf("%d ",S[i]);
  printf("%d\n",S[i]);
  printf("%d\n",count);

  return 0;
}

