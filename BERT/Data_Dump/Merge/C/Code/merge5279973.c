#include<stdio.h>
#include<limits.h>
#define MAX 500000

int n,A[MAX];
int count=0;

void Merge(int A[],int left,int mid, int right){
  int i,j,k, n1,n2, L[MAX],R[MAX];
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0,j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      count++;
      A[k]=L[i];
      i++;
    }else{
      count++;
      A[k]=R[j];
      j++;
    }
  }      
}

void Merge_Sort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}

int main(){
  int i,n, left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  left = 0;
  right = n;
  Merge_Sort(A,left,right);

  printf("%d ",A[0]);
  for(i=1;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}
