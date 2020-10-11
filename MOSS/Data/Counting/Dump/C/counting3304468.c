#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001

int main(){
  int i,j,n,k=0;
  int *A,*B,*C;
  scanf("%d",&n);
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  C=malloc(sizeof(int)*k+1);
  for(i=0;i<k;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  for(i=0;i<=k;i++){
    C[i]+=C[i-1];
  }
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n+1;i++){
    if(i==1)printf("%d",B[i]);
   else printf(" %d",B[i]);
  }
  printf("\n");
  free(A);
  free(B);
  free(C);
  return 0;
}

