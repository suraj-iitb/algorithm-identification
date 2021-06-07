#include <stdio.h>
#define N 1000000

int main(void)
{

  int i,j,n,m,key,count=0;
  int s[N],t[N];
  int left,mid,right;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }

  scanf("%d",&m);
  for(j=0;j<m;j++)
    {
      scanf("%d",&t[j]);
    }
  

  for(j=0;j<m;j++)
    {
      left = 0;
      right = n;
      key = t[j];
      while(left < right)
	{
	  mid = (left + right) / 2;
	  if(s[mid] == key)
	    {
	      count++;
	      break;
	    }
	  else if(key < s[mid])
	    {
	      right = mid;
	    }
	  else
	    {
	      left = mid + 1;
	    }
	}
    }
  printf("%d\n",count);
  return 0;
}
