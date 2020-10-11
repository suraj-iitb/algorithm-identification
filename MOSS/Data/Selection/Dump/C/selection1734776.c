#include <stdio.h>
#define N 100
int main()
{
  int i, j, n, minj, A[N], temp, ccount=0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&A[i]);
    }
  for(i = 0 ; i < n ; i++)
    {
      minj=i;
      for(j = i ; j < n ; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj=j;
	    }
	}
      if(A[i]!=A[minj]) ccount++;

      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
    }
  for(i = 0 ; i < n ; i++)
    {
      if(i==n-1)
	{
	  printf("%d\n",A[i]);
	}else{
	printf("%d ",A[i]);
      }
    }
  printf("%d\n",ccount);
  return 0;
}
