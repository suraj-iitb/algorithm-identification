#include<stdio.h>

int main()
{
  int n,q;
  int S[100000],T[50000];
  int i,j,cnt;
  int left,right,mid,key;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }

  scanf("%d",&q);
  for(j=0;j<q;j++)
    {
      scanf("%d",&T[j]);
    }
  cnt=0;

  for(j=0;j<q;j++)
    {
      key=T[j];
      left=0;
      right=n;
      while(left<right)
	{
	  mid=(left+right)/2;
	  if(S[mid]==key)
	    {
	      cnt++;
	      break;
	    }

	  else if(key<S[mid]) right=mid;

	  else left=mid+1;
	}
    }
  printf("%d\n",cnt);

  return 0;
  
  
}

