#include <stdio.h>
#define N 100000
#define Q 50000

int main()
{
  int n,s[N],q,t[Q],i,left,right,mid,result;
  int cnt=0;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++)
    {
      scanf("%d",&s[i]);
    }

  scanf("%d",&q);
  for(i=0 ; i<q ; i++)
    {
      scanf("%d",&t[i]);
    }

  for(i=0 ; i<q ; i++)
    {
      left = 0;
      right = n;
      while(left < right)
	{
	  mid = (left + right) / 2;
	  if(s[mid] == t[i])
	    {
	      cnt++;
	      break;
	    }
	  else if(t[i] < s[mid]) right = mid;
	  else left = mid + 1;
	}
    }

  printf("%d\n",cnt);

}

