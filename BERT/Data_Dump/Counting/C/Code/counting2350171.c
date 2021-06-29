#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main(){
  int *A,*B,C[N+1],a=0,n,i,j;

  scanf("%d",&n);

  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }

  for(i=0;i<=N;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j+1]]=C[A[j+1]]+1;
  }
  for(i=1;i<=N;i++){
    C[i]=C[i]+C[i-1];
  }
  
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
    
  }

  for(i=1;i<n;i++){
  printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}
