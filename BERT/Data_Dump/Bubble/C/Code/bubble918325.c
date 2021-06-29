#include <stdio.h>

main()
{
  int length, i, j, tmp, count = 0;
  int A[100];

  scanf("%d", &length);

  for(i = 0; i < length; i++)
    {
      scanf("%d", &A[i]);
    }

  for(i = 0; i < length; i++)
    {
      for(j = length - 1; j >= i + 1; j--)
	{
	  if(A[j] < A[j - 1])
	    {
	      tmp = A[j];
	      A[j] = A[j - 1];
	      A[j - 1] = tmp;
	      count++;
	    }
	}
    }
  for(i = 0; i < length; i++)
    {
      if(i == length - 1)
	{
	  printf("%d\n", A[i]);
	}
      else
	{
	  printf("%d ", A[i]);
	}
    }
  printf("%d\n", count);
  return 0;
}
