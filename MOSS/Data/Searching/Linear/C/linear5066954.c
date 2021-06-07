#include <stdio.h>

int main()
{
  int n,s[10000],t[10000],c,q,i,j,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }
  scanf("%d",&q);
  for(j=0;j<q;j++)
    {
      scanf("%d",&t[j]);
    }
  for(i=0;i<q;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(s[j]==t[i])
	    {
	      cnt++;
	      break;
	    }
	}
    }
  printf("%d\n",cnt);
  return 0;
}

