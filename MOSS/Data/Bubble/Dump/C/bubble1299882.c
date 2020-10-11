#include <stdio.h>
#include <stdlib.h>
main()
{

  int j;
  int length;
  int temp;
  int *buf;
  int sum = 0;
  int flag;

  scanf("%d",&length);

  buf = (int *)malloc(sizeof(int)*length);

  for(j = 0;j < length;j++)
    {
      scanf("%d",&buf[j]);
    }

  while(1)
    {
      flag = 0;
      for(j = length - 1;j > 0;j--)
	{
	  if(buf[j] < buf[j - 1])
	    {
	      temp = buf[j - 1];
	      buf[j - 1] = buf[j];
	      buf[j] = temp;
	      sum++;
	      flag = 1;
	    }
	}
      if(flag == 0) break;
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
  printf("%d\n",sum);
return 0;
}
