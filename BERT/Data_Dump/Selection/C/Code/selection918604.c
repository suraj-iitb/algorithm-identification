#include<stdio.h>
#define MAX 100
int main()
{
  int i,j,count=0;
  int array[MAX];
  int x,min=0,tmp=0;
 
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
      scanf("%d",&array[i]);
    }
  for(i=0;i<x;i++)
    { 
      min = i;
      for(j=i;j<x;j++)
	{
	  if(array[j] <array[min])
	    {
	      min = j;
	    }
	}
      if(i!=min)
	{
	  count++;
	  tmp = array[i];
	  array[i] = array[min];
	  array[min] = tmp;
	}
    }
  for(i=0;i<x;i++)
    {
      printf("%d",array[i]);
      if(i != x-1)
	{
	  printf(" ");
	}
      else printf("\n");
    }
  printf("%d\n",count);
  return 0;
}
