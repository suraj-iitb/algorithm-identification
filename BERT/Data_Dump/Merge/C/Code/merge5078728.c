#include<stdio.h>
#include<stdlib.h>
#define N 500000
#define INFTY 1000000000

int count = 0;
void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(){
  int n,*S,i;
  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i = 0;i < n;i++)scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i = 0;i < n;i++){
    if(i == n - 1)printf("%d\n",S[i]);
    else printf("%d ",S[i]);
  }
  printf("%d\n",count);
  return 0;
}

void merge(int A[],int left,int mid,int right){
  int n1 = mid - left,n2 = right - mid,L[N],R[N],i,j,k;
  for(i = 0;i <= n1 - 1;i++)L[i] = A[left + i];
  for(i = 0;i <= n2 - 1;i++)R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k <= right - 1;k++){
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

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

