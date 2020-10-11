#include <stdio.h>

main()
{
  int length, i, j, count = 0, tmp, min, flag = 0;
  int A[100];

  scanf("%d", &length);

  for(i = 0; i < length; i++)
    {
      scanf("%d", &A[i]);
    }

  for(i = 0; i < length; i++)
    {
      min = i;
      for(j = i + 1; j < length; j++)
	{
	  if(A[j] < A[min])
	    {
	      min = j;
	      flag = 1;
	    }
	}
      if(flag == 1)
	{
	  tmp = A[i];
	  A[i] = A[min];
	  A[min] = tmp;
	  count++;
	}
      flag = 0;
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
