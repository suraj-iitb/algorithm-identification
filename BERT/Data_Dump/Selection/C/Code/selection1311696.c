#include <stdio.h>
#include <stdlib.h>
main()
{

  int i;
  int j;
  int length;
  int temp;
  int *buf;
  int minj;
  int sum = 0;

  scanf("%d",&length);
 
  buf = (int *)malloc(sizeof(int)*length);

  for(i = 0;i < length;i++)
    {
      scanf("%d",&buf[i]);
    }

  for(i = 0;i < length;i++)
    {
      minj = i;
      for(j = i;j < length;j++)
	{
	  if(buf[j] < buf[minj])
	    {
	      minj = j;
	    }
	}
      if(buf[i] != buf[minj])
	{
	  temp = buf[i];
	  buf[i] = buf[minj];
	  buf[minj] = temp;
	  sum++;
	}
    }

  for(i = 0;i < length;i++)
    {
      printf("%d",buf[i]);
      if(i != length - 1)
	{
	  printf(" ");
	}
    }
  printf("\n");
  printf("%d\n",sum);
  return 0;
}
