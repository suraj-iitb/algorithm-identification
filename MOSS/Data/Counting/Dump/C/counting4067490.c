#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int*,int*,int*,int,int);

int main(){
  int n,i,k=-1;
  scanf("%d",&n);

  int A[n],B[n],C[VMAX+1];

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k)k=A[i];
  }

  CountingSort(A,B,C,n,k);

  for(i=1;i<=n;i++){
    if(i==n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }

  return 0;
}

void CountingSort(int *A,int *B,int *C,int n,int k){
  int i,j;

  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  
  i=0;
  
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
  
}

