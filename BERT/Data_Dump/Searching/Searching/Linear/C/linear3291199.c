#include <stdio.h>
#define N 10000
#define Q 500

int main()
{
  int n,s[N],q,t[Q],i,j;
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

  for(j=0 ; j<q ; j++)
    {
      i=0;
      s[n] = t[j];
      while(s[i] != t[j])
	{
	  i++;
	}
      if(i!=n) cnt++;
    }
    

  printf("%d\n",cnt);
  
  return 0;
}

