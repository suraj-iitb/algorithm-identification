#include<stdio.h>
#include <stdlib.h>

int main(){
  int i,j,n,C[10001];
  unsigned short *A, *B,k=10000;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++){
    scanf("%hd",&A[i]);
  }
  
  for(i=0;i<=k;i++) C[i]=0;
  for(j=1;j<=n;j++) C[A[j]]++;
  for(i=1;i<=k;i++) C[i]+=C[i-1];

  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  return 0;
}


  

  

  

