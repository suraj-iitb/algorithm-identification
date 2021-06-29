#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define NMAX 10000



int main()
{
  unsigned short *A, *B;
  int C[NMAX+1];
  int n, i, j,mx;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++)
  {
    scanf("%d",&A[i]);
  }

  mx=0;
  for(i=1;i<=n;i++)
  {
    if(mx<A[i])
    {
      mx=A[i];
    }
  }
  for(i=0;i<=mx;i++)
  {
    C[i]= 0;
  }

  for(j=1;j<=n;j++)
  {
    C[A[j]]=C[A[j]]+1;
  }

  for(i=1;i<=mx;i++)
  {
    C[i]=C[i]+C[i-1];
  }

 
  
  for(j=n;j>=0;j--)
  {
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }

  

  for(i=1;i<=n;i++)
  {   
    printf("%d",B[i]);
    if(i<n){
      printf(" ");
    }
    }

  printf("\n");



  return 0;
}
