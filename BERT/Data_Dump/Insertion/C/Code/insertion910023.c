#include <stdio.h>

main()
{
  int j, i, length, key;
  int A[100];
  
  scanf("%d", &length);
  
  for(i = 0; i < length; i++)
    {
      scanf("%d", &A[i]);
    }

  for(j = 0; j < length; j++)
    {
      if(j == length - 1)
	{
	  printf("%d\n", A[j]);
	}
      else
	{
	  printf("%d ", A[j]);
	}
    }

  for(i = 1; i < length; i++)
    {
      key = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > key)
	{
	  A[j + 1] = A[j];
	  j = j - 1;
	}
      A[j + 1] = key;
      for(j = 0; j < length; j++)
	{
	  if(j == length - 1)
	    {
	      printf("%d\n", A[j]);
	    }
	  else
	    {
	      printf("%d ", A[j]);
	    }
	}
    }
  return 0;
}
