#include <stdio.h>
#include <stdlib.h>
main()
{
  int i;
  int j;
  int length;
  int key;
  int *buf;

  scanf("%d",&length);

  buf = (int *)malloc(sizeof(int)*length);

  for(i = 0;i < length;i++)
    {
      scanf("%d",&buf[i]);
    }

  for(i = 1;i < length;i++)
    {
      for(j = 0;j < length;j++)
	{
	  printf("%d",buf[j]);
	  if(j != length - 1)
	    {
	      printf(" ");
	    }
	}
      printf("\n");
      key = buf[i];
      j = i - 1;
      while(j >= 0 && buf[j] > key)
	{
	  buf[j + 1] = buf[j];
	  j--;
	  buf[j + 1] = key;
	}
    }
  for(j = 0;j < length;j++)
    {
      printf("%d",buf[j]);
      if(j != length - 1)
	{
	  printf(" ");
	}
    }
  printf("\n");
  return 0;
}
