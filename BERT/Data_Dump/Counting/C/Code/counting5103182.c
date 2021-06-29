#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define N 10000

int main(void){
  unsigned short *A,*B;

  int i,n,j,C[N+1];

  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<=N;i++)
    C[i]=0;
  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }
  for(i=1;i<=N;i++)
    C[i]=C[i]+C[i-1];
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    if(i>1)
      printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

