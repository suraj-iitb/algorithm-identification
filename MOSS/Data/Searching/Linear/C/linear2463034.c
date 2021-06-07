#include<stdio.h>
#define SIZE 10000
int main()
{
  int s[SIZE],t;
  int i,j,n,q,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&t);
      for(j=0;j<n;j++)
	{
	  if(t==s[j])
	    {
	      ans++;
	      break;
	    }
	}
    }
  printf("%d\n",ans);
  return 0;
}
