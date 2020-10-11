#include<stdio.h>
#include<limits.h>
//INT_MINはint型の最小値
//INT_MAXはint型の最大値

int L[250001];
int R[250001];

void merge(int*,int,int,int);
void mergesort(int*,int,int);

int count=0;

int main(){
  int n,i;
  int A[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  int LEFT=0;
  int RIGHT=n;
 
  mergesort(A,LEFT,RIGHT);
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",A[i]);
    else
      printf("%d ",A[i]);
  }

  printf("%d\n",count);
  return 0;
}


void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
 
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];
  
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    // printf("merged.A[%d]:%d\n",k,A[k]);
  }
 
}

void mergesort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

