#include<stdio.h>
#define MAX 100
int main()
{
  int i,j;
  int x,y,count=0;
  int array[MAX];
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
      scanf("%d",&array[i]);
    }
  for(i=0;i<x;i++)
    {
      for(j=x-1;j>=1;j--)
	{
	  if(array[j] < array[j-1])
	    {
	      y = array[j-1];
	      array[j-1] = array[j];
	      array[j] = y;
	      count++;
	    }
	}
    }
  for(i=0;i<x;i++)
    {
      printf("%d",array[i]);
      if(i !=x-1)
	{
	  printf(" ");
	}
      else
	{
	  printf("\n");
	}
    }
  printf("%d\n",count);
  return 0;
}
