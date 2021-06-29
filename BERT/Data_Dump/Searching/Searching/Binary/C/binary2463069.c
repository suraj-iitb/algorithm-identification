#include<stdio.h>
#define SIZE 100000
int main()
{
  int s[SIZE],t;
  int i,j,k,n,q,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&t);
      j=0;
      k=n-1;
      while(j<k)
	{
	  if(t==s[(j+k)/2])
	    {
	      ans++;
	      break;
	    }
	  else if(t>s[(j+k)/2]) j=(j+k)/2;
	  else if(t<s[(j+k)/2]) k=(j+k)/2;
	  if(k-j<=1)
	    {
	      if((t==s[j])||(t==s[k])) ans++;
	      break;
	    }
	}
    }
  printf("%d\n",ans);
  return 0;
}
