#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main()
{
  int i,j,k,C[N+1];
  unsigned short *A,*B;
  scanf("%d",&k);
  A=malloc(sizeof(short)*k+1);
  B=malloc(sizeof(short)*k+1);
  for(i=0;i<=N;i++)
    {
      C[i]=0;
    }
  for(i=0;i<k;i++)
    {
      scanf("%hu",&A[i+1]);
      C[A[i+1]]++;
    }
  for(i=1;i<=N;i++)
    {
      C[i]+=C[i-1];
    }
  for(j=1;j<=k;j++)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
  for(i=1;i<=k;i++)
    {
      if(i!=1) printf(" ");
      printf("%d",B[i]);
    }
  printf("\n");
  
  return 0;
}
