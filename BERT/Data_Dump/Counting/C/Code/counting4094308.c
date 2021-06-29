#include <stdio.h>

int C[10001],D[10001];

int main()
{
  int n,i,basho=0;

  scanf("%d",&n);

  int A[n],B[n],maxA=0;

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      C[A[i]]++;
    }
  
  for(i=0;i<10001;i++)
    {
      basho+=C[i];
      D[i]=basho-1;
    }

  for(i=0;i<n;i++)
    {
      B[ D[A[i]] ]=A[i];
      D[A[i]]--;
    }

  for(i=0;i<n-1;i++)printf("%d ",B[i]);
  printf("%d\n",B[n-1]);

      
  return 0;
}

