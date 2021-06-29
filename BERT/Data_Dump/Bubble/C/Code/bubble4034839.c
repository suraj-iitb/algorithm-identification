#include <stdio.h>

int main()
{
  int N,i,j,flag=1,count=0;
  scanf("%d",&N);
  int bubble[N];
   for(j=0;j<N;j++)
    {
      scanf("%d",&bubble[j]);
    }
  while(flag)
    {
      flag=0;
      for(j=N-1;j>0;j--)
	{
	  if(bubble[j]<bubble[j-1])
	    {
	      count++;
	      i=bubble[j];
	      bubble[j]=bubble[j-1];
	      bubble[j-1]=i;
	      flag=1;
	    }
	}
    }
  for(j=0;j<N-1;j++)
    {
      printf("%d ",bubble[j]);
    }
  printf("%d\n",bubble[N-1]);
  printf("%d\n",count);
  return 0;
}

