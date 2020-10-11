#include<stdio.h>

#define INF 1000000001

int count;

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(){
  int i,n;
  int S[500000];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++)printf("%d ",S[i]);
  printf("%d\n",S[i]);
  printf("%d\n",count);
  
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int i,j,k,n1,n2;
  int L[250001],R[250001];
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=INF;
  R[n2]=INF;
  
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

