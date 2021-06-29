#include <stdio.h>
#define N 100
int main()
{
  int i, j,v,n,k;
  int A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }


  for(i=1;i<=n-1;i++)
    {
      for (k = 0; k <=n-1 ; k++)
        {
          if(k!=n-1)printf("%d ",A[k]);
          else printf("%d\n",A[k]);
        }

      v=A[i];
      j = i-1;
      while ((j >= 0) && (A[j] > v))
        {
          A[j+1] = A[j];
          j--;
        }

      A[j+1]=v;
    }

  for (k = 0; k <=n-1 ; k++)
        {
          if(k!=n-1)printf("%d ",A[k]);
          else printf("%d\n",A[k]);
        }


  return 0;
}






