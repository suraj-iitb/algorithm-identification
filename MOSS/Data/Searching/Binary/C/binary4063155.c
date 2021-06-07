#include <stdio.h>


int main()
{
  int i,n,q,count=0,t,left,right,s,mid,flip;
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
      for(t=s+1;t<q;t++)
	{
	  if(T[s]==T[t])
	    {
	      break;
	    }	 
	}
      left=0;
      right=n;
      while(left<right)
	    {
	      //printf("left%d,right%d,mid%d\n",left,right,mid);
	      mid=(left+right)/2;
	     
	      if(S[mid]==T[s])
		{
		  count++;
		  break;
		}
	      else if (T[s]<S[mid])
		right =mid;
	      else
		left=mid+1;
	    }
    } 
   printf("%d\n",count);
   return 0;
}

