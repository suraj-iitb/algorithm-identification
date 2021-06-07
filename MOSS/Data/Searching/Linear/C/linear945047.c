#include<stdio.h>

#define MAX1 10000
#define MAX2 500
int main()
{
  int n,m,i,j;
  int count=0;
  int s[MAX1];
  int t[MAX2];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }

  scanf("%d",&m);
  for(i=0;i<m;i++)
    {
      scanf("%d",&t[i]);
    }

  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(s[j]==t[i])
	    {
	      count+=1;
	      break;
	    }
	}
    }
  printf("%d\n",count);
  return 0;
}
