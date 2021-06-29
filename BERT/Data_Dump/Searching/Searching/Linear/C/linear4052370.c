#include <stdio.h>

int search(int *,int);

int main()
{
  int i,n,q,s,count=0,t,flip=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
    } 
  for(s=0;s<q;s++)
    {
      flip=0;
      for(t=s+1;t<q;t++)
	{
	  if(T[s]==T[t])
	    {
	      flip=1;
	      break;
	    }
	}
      //printf("flip%d\n",flip);
      if(flip!=1)
	{
	  i=0;
	  while(S[i]!=T[s])
	    {
	  i++;
	  if(i==n)
	    break;
	    }
	  if(i!=n)
	    {
	  count++;
	    }
	}
    }
  printf("%d\n",count);
  return 0;
}

