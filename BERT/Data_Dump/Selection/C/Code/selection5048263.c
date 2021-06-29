#include <stdio.h>
#define N 100
int main()
{
  int A[N],i,j,n,minj,keep,count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);

  for(i = 0; i < n; i++)
    {
      minj = i;
      for(j = i; j < n; j++)
	{
	  if(A[j] < A[minj])
	    minj = j;	      	  
	}
      if(minj != i) count++;
      keep = A[i];
      A[i] = A[minj];
      A[minj] = keep;
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
  

