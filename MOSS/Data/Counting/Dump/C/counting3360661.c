#include <stdio.h>
#define N 2000001
int main()
{
  int n,A[N],i,j,B[N],count,C[N],D[N],a,max=0;
  FILE *fp;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d",&A[i]);
      if(max<A[i])
	max=A[i];
    }
  for(i=0;i<=max;i++)
    {
      C[i]=0;
    }
  for(j=1;j<=n;j++)
    C[A[j]]++;
  for(i=0;i<=max;i++)
    {
      C[i]=C[i-1]+C[i];
    }
  for(j=n;j>=1;j--)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
  for(i=1;i<=n;i++)
    {
      printf("%d",B[i]);
      if(i!=n)
	printf(" ");
    }
  printf("\n");
  return 0;
}

