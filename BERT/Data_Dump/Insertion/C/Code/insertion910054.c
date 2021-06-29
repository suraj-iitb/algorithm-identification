#include<stdio.h>
#define N 100
int main()
{
  int x,i,j,k,key;
  int y[N];
  scanf("%d",&x);
  for(i=0;i<x;i++)
    {
      scanf("%d",&y[i]);
    }
  for(i=0;i<x;i++)
    {
      printf("%d",y[i]);
      if(i != x-1)
	{
	  printf(" ");
	}
    }
  printf("\n");
  for(i=1;i<x;i++)
    {
      key = y[i];
      j = i - 1;
      while((j >= 0) && (y[j] > key))
	{
	  y[j+1] = y[j];
	  j--;
	}
      y[j+1] = key;
      for(k=0;k<x;k++)
	{
	  printf("%d",y[k]);
	  if(k != x-1)
	    {
	      printf(" ");
	    }
	}
      printf("\n");
    }
  return 0;
}
