#include <stdio.h>
#include <stdlib.h>
#define N 100000
int main()
{
  int i,j,n,q,S[N],T[N],count = 0;
  int left,right,mid;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    scanf("%d",&T[i]);
  for(i = 0;i < q; i++)
    {
      left = 0;
      right = n;
      
      while(left < right)
	{
	  mid = (left+right)/2;
	  if(S[mid] == T[i]){
	    count++;
	    break;
	  }
	  else if(S[mid] > T[i])
	    right = mid;
	  else left = mid + 1;
	}
    }

  printf("%d\n",count);
  return 0;
}


