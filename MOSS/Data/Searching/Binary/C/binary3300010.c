#include <stdio.h>
#define n 100000
#define q 50000
int main()
{
  int S[n],T[q],es,et,i,j=0,left,right,mid,C=0;
  scanf("%d",&es);
  for(i=0;i<es;i++)
    scanf("%d",&S[i]);
  scanf("%d",&et);
  for(i=0;i<et;i++)
    scanf("%d",&T[i]);

  
  for(i=0;i<et;i++)
    {
      //if(i!=0) printf("^%d^",T[i-1]);
      left=0;
      right=es;
      while(1)
	{
	  if(left>right)
	    {
	      break;
	    }
	  mid=(left+right)/2;
	  //printf("%d ",mid);
	  if(S[mid]==T[i])
	    {
	      //printf("%d\n",T[i]);
	      C++;
	      break;
	    }
	  if(left==right) break;
	  if(S[mid]>T[i])
	    {
	      right=mid;
	      continue;
	    }
	  else if(S[mid]<T[i])
	    {
	      left=mid+1;
	      continue;
	    }
	}
    }
  printf("%d",C);
  printf("\n");
  return 0;
}

