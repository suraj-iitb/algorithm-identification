#include<stdio.h>
int main()
{
  int left,right,mid,C=0,i,n,q,S[100000],T[50000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
      left=0;
      right=n;
  
      while(right>left)
	{
	  mid=(right+left)/2;
	  if(S[mid]==T[i])
	    {
	      C++;
	      break;
	    }
	  else if(T[i]<S[mid])
	    {
	      right=mid;
	    }
	  else left=mid+1;
	}
    }
     
  printf("%d\n",C);
	 
  return 0;
}

