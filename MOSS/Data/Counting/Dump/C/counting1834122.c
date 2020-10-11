#include <stdio.h>
#include <stdlib.h>
#define ABMAX 10001
#define CMAX 2000000

int main(){
  int i,j,n,k=0,*A,*B,C[CMAX];

  scanf("%d",&n);
  
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k)
      k=A[i];
  }
  
  for(i=0;i<=k+1;i++)
    C[i]=0;

  for(j=1;j<=n;j++)
    C[A[j]]++;

  for(i=1;i<=k+1;i++)
    C[i]=C[i]+C[i-1];

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  printf("%d",B[1]);
  for(i=2;i<=n;i++)
    printf(" %d",B[i]);
  printf("\n");

  return 0;
}
