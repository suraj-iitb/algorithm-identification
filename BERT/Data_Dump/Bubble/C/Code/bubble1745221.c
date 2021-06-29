#include <stdio.h>
#define N 100


int main()
{
  int i,j,num,count=0,flag,data[N],change;

  scanf("%d",&num);

  for(i = 0 ; i < num ; i++)
    {
      scanf("%d",&data[i]);
    }

  flag =  1;
  while(flag)
    {
      flag = 0;
      for(j = num -1 ; j >= 1 ; j--)
	{
	  if(data[j] < data[j-1])
	    {
	      change = data[j];
	      data[j] = data[j-1];
	      data[j-1] = change;
	      flag = 1;
	      count++;

	    }
	}

    }
  for(i = 0 ; i < num ; i++)
    {
      printf("%d",data[i]);
      if(i != num-1)printf(" ");
      

    }

  printf("\n%d\n",count);
  return 0;
}
