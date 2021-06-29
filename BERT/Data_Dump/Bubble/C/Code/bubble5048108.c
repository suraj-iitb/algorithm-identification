#include <stdio.h>
#define N 100
int main()
{
  int A[N],flag,i,n,keep,count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);

  flag = 1;

  while(flag)
    {
      flag = 0;
      for(i = n - 1; i >0; i--)
	{
	  if(A[i] < A[i - 1])
	    {
	      keep = A[i];
	      A[i] = A[i-1];
	      A[i - 1] = keep;
	      flag = 1;
	      count++;
	    }
	}
    }
  for(i = 0; i < n; i++)
    {
      printf("%d",A[i]);
      if(i != n - 1) printf(" ");
      if(i == n - 1) printf("\n");
    }  
  printf("%d\n",count);
  
  return 0;
}

