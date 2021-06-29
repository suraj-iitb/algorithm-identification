#include <stdio.h>
#define N 100
#define MAX 1000
int main()
{
  int i,j,A[N],v,n,c;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&A[i]);
      if(A[i] >MAX)printf("error\n");
    }
  
 
  for(i = 1;  i < n+1; i++)
    {
      v = A[i];
      j = i - 1;

      for(c = 0; c < n-1; c++)
	{
	  printf("%d ",A[c]);
	}
      printf("%d",A[c]);
      printf("\n");
      
      while (j >= 0 && A[j] > v)
	{
	  A[j+1] = A[j];
	  j--;
	 
	}
      A[j+1] = v;
    }
  return 0;
}

