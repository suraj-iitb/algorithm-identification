#include<stdio.h>
#define Max 100000 
int main()
{
  int S[Max],T[Max],i,j,n,q;
  int left,mid,right;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  j=0;
  for(i=0;i<q;i++)
    {
      left=0;
      right=n;
      while(left<right)
	{
	  mid = (left + right)/2;
	  if(S[mid] == T[i])
	    {
	      j++;
	      break;
	    }
	  else if (T[i] < S[mid])
	    right = mid;

	  else left = mid + 1;
	}
    }
  printf("%d\n",j);
  return 0;
}
