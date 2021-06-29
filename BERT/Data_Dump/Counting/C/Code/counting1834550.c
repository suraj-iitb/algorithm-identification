#include <stdio.h>
#define k 20000001
int A[k],B[k],C[k];
int main()
{
  int i,n;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i+1]);
      C[i]=0;  
    }

  for(i=1;i<=n;i++)
    {
      C[A[i]]=C[A[i]]+1;
    }
  for(i=1;i<k;i++)
    {
      C[i]=C[i]+C[i-1];
    }
  for(i=n;i>0;i--)
    {
      B[C[A[i]]]=A[i];
      C[A[i]]=C[A[i]]-1;
    }

  for(i=1;i<=n-1;i++)
    {
      printf("%d ",B[i]);
    }
  printf("%d\n",B[i]);
  return 0;
}
