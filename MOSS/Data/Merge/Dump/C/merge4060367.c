#include<stdio.h>
#define INFTY 1000000000
#define N 500000

void mergeSort(int[],int,int,int);
int merge(int[],int,int,int,int);

int count=0;

int main(){
  int S[N];
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,n,0,n);

  for(i=0;i<n;i++){
    if(i){
      printf(" ");
    }
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);
}

void mergeSort(int A[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
    }
}

int merge(int A[],int n,int left,int mid,int right){
 
  int n1,n2,j,k,i;
  

  n1=mid-left;
  n2=right-mid;
  int L[n1];
  int R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }

  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
  }
    count++;
}
}

