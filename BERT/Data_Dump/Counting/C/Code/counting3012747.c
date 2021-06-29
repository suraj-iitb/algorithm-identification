#include <stdio.h>
#include <stdlib.h>
#define V 10000
int main(){
  int i,j,n;
  int *A,*B;
  int C[V+1];
  scanf("%d",&n);
  A=malloc(sizeof(int)*n);
  B=malloc(sizeof(int)*n);
  for(i=0;i<=V;i++) C[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }
  for(i=1;i<=V;i++) C[i]+=C[i-1];
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    if (i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
}



