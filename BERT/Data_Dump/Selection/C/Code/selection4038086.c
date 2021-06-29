#include <stdio.h>
#define N 100
int main()
{
  int ele,haire[N],minnum,i,j,hokan=0,cou=0,bunki=0;
  scanf("%d",&ele);
  for(i=0;i<ele;i++)
    {
      scanf("%d",&haire[i]);
      //minnum=haire[i];
    }
  // minnum=haire[0];
  for(i=0;i<ele;i++)
    {
      minnum=i;
      for(j=i;j<ele;j++)
	{
	  if(haire[j]<haire[minnum])
	    {
	      minnum=j;
	      bunki=1;
	    }
	  //cou++;
	}
      if(bunki==1)
	{
	  hokan=haire[i];
	  haire[i]=haire[minnum];
	  haire[minnum]=hokan;
	  cou++;
	}
      bunki=0;
    }
  for(i=0;i<ele;i++)
    {
      if(i<ele-1)
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

