#include <stdio.h>
#define YOU 1000
int main()
{
  int nyugyo,haire[YOU],i,j,v,w;
  scanf("%d",&nyugyo);
  for(i=0;i<nyugyo;i++)
    {
      scanf("%d",&haire[i]);
      if(i<nyugyo-1)
	{
	  printf("%d ",haire[i]);
	}
      else
	{
	  printf("%d",haire[i]);
	}
    }
  printf("\n");
  for(i=1;i<nyugyo;i++)
    {
      v=haire[i];
      j=i-1;
      while((j>=0)&&(haire[j])>v)
	{
	  haire[j+1]=haire[j];
	  j--;
	}
      haire[j+1]=v;
      for(w=0;w<nyugyo;w++)
	{
	  if(w<nyugyo-1)
	    {
	      printf("%d ",haire[w]);
	    }
	  else
	    {
	      printf("%d",haire[w]);
	    }
	}
      printf("\n");
    }

  return 0;
}
/*
 if(haire[i]>haire[i+1])
	{
	  haire[i+1]=haire[i];
	  for(i=0;i<nyugyo;i++)
	    {
	      printf("%d ",haire[i]);
	    }
	  i++;
	}
      for(i=0;i<nyugyo;i++)
	{
	  printf("%d ",haire[i]);
	}
 */


