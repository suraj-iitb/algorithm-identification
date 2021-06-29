#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
int main()
{
  int n,j,*A,*B,i,c[VMAX+1];
  scanf("%d",&n);
  A=(int *)malloc((n+1) * sizeof(int));
  for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
  B=(int *)malloc(sizeof(int)*(n+1));

  for(i=0;i<=VMAX;i++)
    c[i]=0;

  for(j=1;j<=n;j++)
    c[A[j]]++;

  for(i=1;i<=VMAX;i++)
    c[i]=c[i] + c[i-1];

  for(j=n; j>=1;j--)
    {
      B[c[A[j]]] = A[j];
      c[A[j]]--;
    }

  for(i=1;i<n;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);
  return 0;
}

