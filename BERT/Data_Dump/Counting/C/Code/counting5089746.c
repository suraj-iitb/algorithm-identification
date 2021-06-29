#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main()
{
  unsigned short *A,*B;
  int C[VMAX+1];
  int n,i,j,k=0;

  scanf("%d",&n);
  if(!(n>=1 && n<=2000000)) exit(1);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++)
    {
      scanf("%d",&A[i]);
      if(!(A[i]>=0 && A[i]<=10000));
      if(k<A[i]) k=A[i];
    }

  for(i=0;i<=k;i++) C[i] = 0;

  for(j=1;j<=n;j++) C[A[j]]++;

  for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];

  for(i=n;i>=1;i--)
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }

  for(i=1;i<=n-1;i++)
    {
      printf("%d ",B[i]);
    }
  printf("%d\n",B[i]);

  free(A);
  free(B);
  return 0;
}

