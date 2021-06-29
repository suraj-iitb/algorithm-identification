#include <stdio.h>

#define N 100

int main()
{
  int n,i,min,j,tmp,cnt = 0;

  int A[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++)scanf("%d",&A[i]);

  for(i = 0; i < n; i++)
    {
      min = i;
      for(j = i; j < n; j++)
	{
	  if(A[j] < A[min])min = j;
	}
      if(min != i)
	{
      tmp = A[min];
      A[min] = A[i];
      A[i] = tmp;
      cnt++;
	}


    }
	    
  for(i = 0; i < n-1; i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  
  


  
  return 0;
  
}

