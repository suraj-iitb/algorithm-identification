#include<stdio.h>
#define MAX 100

main()
{
  int i, j, N, A[MAX], irekae, flag=1, count=0;

  scanf("%d", &N);
  for(i=0; i<N; i++)
    {
      scanf("%d", &A[i]);
    }

  while(flag)
    {
      flag = 0;
      for(j=N-1; j>0; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      irekae = A[j];
	      A[j] = A[j-1];
	      A[j-1] = irekae;
	      count++;
	      flag = 1;
	    }
	}
    }

  for(i=0; i<N; i++)
    {
      printf("%d", A[i]);
      if(i<N-1)
	{
	  printf(" ");
	}
    }
  printf("\n");
  printf("%d\n", count);

  return 0;  
}
