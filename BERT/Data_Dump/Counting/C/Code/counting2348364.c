#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define AMAX 10000

int main()
{
  int n,i,j;
  int c[AMAX+1];
  int *A,*B;

  scanf("%d",&n);

  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);

  for(i=0;i<AMAX;i++){
    c[i]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    c[A[i+1]]++;
  }

  for(i=1;i<=AMAX;i++){
    c[i]=c[i]+c[i-1];
  }

  for(j=1;j<=n;j++){
    B[c[A[j]]]=A[j];
    c[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }

  printf("\n");

  return 0;
}
