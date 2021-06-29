#include <stdio.h>

int main()
{
  int i,b,k[100],n,a=0,o=0,v,j;
  scanf("%d",&a);
  for(b=0;b<a;b++)
    {
      scanf("%d",&n);
      k[b]= n;
      
    }

   for(b=0;b<a-1;b++)
	{
	  printf("%d ",k[b]);
	}
      printf("%d",k[b]);
      printf("\n");
  for(i=1;i<a;i++)
    {
      v = k[i];
      j = i-1;
      
      while(j>=0 && k[j]>v)
	{
	  k[j+1] = k[j];
	    j--;
	  
	}
      k[j+1] = v;
      for(b=0;b<a-1;b++)
	{
	  printf("%d ",k[b]);
	}
      printf("%d",k[b]);
      printf("\n");
    }
  
  return 0;
}

