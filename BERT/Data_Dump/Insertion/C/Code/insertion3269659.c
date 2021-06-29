#include <stdio.h>
#define N 100

int main()
{
  int i,j,k,n,judg,A[N];

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  for(i = 1;i < n;i++)
    {
      for(j = 0;j < n;j++)
	{
	  printf("%d",A[j]);
	  if(j < n - 1) printf(" ");
	}
      
      judg = A[i];
      k = i - 1;
      while(k >= 0 && A[k] > judg)
	{
	  A[k + 1] = A[k];
	  k--;
	}
      A[k + 1] = judg;
      
      
      printf("\n");
    }
  
  for(j = 0;j < n;j++)
    {
      printf("%d",A[j]);
      if(j < n - 1) printf(" ");
    }
  printf("\n");
  return 0;
}

