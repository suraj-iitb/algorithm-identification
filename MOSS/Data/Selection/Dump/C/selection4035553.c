#include <stdio.h>

int main()
{
  int N,minj,i,j,flag=1,count=0,regard,sign=0,n;
  scanf("%d",&N);
  int insert[N];
  for(j=0;j<N;j++)
    {
      scanf("%d",&insert[j]);
    }
  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(insert[j]<insert[minj])
	    {
	      count=1;
	      minj=j;
	    }
	  if(count==1&&j==N-1)
	    {
	  sign++;
	  count=0;
	    }
	}
     regard=insert[minj];
	      insert[minj]=insert[i];
	      insert[i]=regard;
    }
  for(j=0;j<N-1;j++)
    {
       printf("%d ",insert[j]);
    }
  printf("%d\n",insert[N-1]);
  printf("%d\n",sign);
  return 0;
}

