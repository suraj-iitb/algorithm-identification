#include <stdio.h>

int s[100000];

int binary(int,int);

int main()
{
  int l,r,m,t[50000],c,i,n,q,cnt=0,j;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&t[i]);
    }

  
	
   
  for(i=0;i<q;i++)
    {
       cnt+=binary(n,t[i]);
    }
  printf("%d\n",cnt);
  
  return 0;
}

int binary(int n,int key)
{
  int l,r,m;
  static int cnt=0;
  l=0;
  r=n;
  
  while(l<r)
    {
     
      m=(l+r)/2;
      if (key==s[m])
	{
	  return 1;
	}
      else if(key>s[m])
	{
	  l=m+1;
	}
      else if(key<s[m])
	{
	  r=m;
	}
     
    }
      return 0;


}

