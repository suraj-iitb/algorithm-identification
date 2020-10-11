#include<stdio.h>
#include<stdlib.h>

#define INFTY 1000000000
#define n_max 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int count=0;

int main(){
  int i,n,*p;
  int S[n_max];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  p=&S[0];
  mergeSort(p,0,n);
  
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);
  printf("%d\n",count);
  
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k,*L,*R;

  n1=mid-left;
  n2=right-mid;

  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  
  L[n1]=INFTY;
  R[n2]=INFTY;

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

