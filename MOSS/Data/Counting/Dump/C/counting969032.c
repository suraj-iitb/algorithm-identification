#include <stdio.h>
int A[2000001],B[2000001],C[10001];
int main()
{
  int i,j,n=0;
  int k=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d",&A[i]);
      C[A[i]]++;
      if(k<A[i]) k=A[i];
      // printf("%d ",A[i]);
    }
  for(i=0;i<=k;i++)
    {
      C[i]=C[i]+C[i-1];
    }
  for(j=n;j>=0;j--)
    {     
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
  for(i=1;i<n+1;i++)
    {
      if(i!=n)printf("%d ",B[i]);
      else  printf("%d\n",B[i]);
    }
  return 0;
}
