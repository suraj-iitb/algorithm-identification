#include <stdio.h>
#define N 100
int main()
{
  int yousu,haire[N],bunki,i,cou=0,hokan=0;
  scanf("%d",&yousu);
  for(i=0;i<yousu;i++)
    {
      scanf("%d",&haire[i]);
    }
  bunki=1;
  while(bunki==1)
    {
      bunki=0;
      for(i=yousu-1;i>=1;i--)
	{
	  if(haire[i]<haire[i-1])
	    {
	      hokan=haire[i];
	      haire[i]=haire[i-1];
	      haire[i-1]=hokan;
	      cou++;
	      bunki=1;
	    }
	  //cou++;
	}
      
    }
  for(i=0;i<yousu;i++)
    {
      if(i<yousu-1)
	{
	  printf("%d ",haire[i]);
	}
      else
	{
	  printf("%d",haire[i]);
	}
    }
  printf("\n");
  printf("%d\n",cou);
  return 0;
}

