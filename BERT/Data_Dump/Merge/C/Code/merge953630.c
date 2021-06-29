#include<stdio.h>

#define N 500000

void Merge(int A[],int left,int mid,int right);
void MergeSort(int A[],int left,int right);

int A[N],count=0;

int main(){ 
  int n,q,i;
  int mid,left,right;
  
  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  MergeSort(A,0,n);
  
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]); 
  }
  printf("%d",A[n-1]);
  printf("\n%d\n",count);
  
  return 0;
}

void MergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }
}

void Merge(int A[],int left,int mid,int right){
  int n1=mid-left,n2=right-mid,i,j,k;
  int L[n1],R[n2];
  for(i=0;i<=n1-1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid + i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;
  for(k=left;k<=right-1;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      count++;
      i = i + 1;
    }
    else{
      A[k] = R[j];
      count++;
      j = j + 1;
    }
  }
}
