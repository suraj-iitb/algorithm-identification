#include <stdio.h>

int main()
{
  int n,q,i,j,onaji=0;

  scanf("%d",&n);
  int S[n+1];
  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  for(j=0;j<q;j++)
    {
      i=0;
      S[n]=T[j];
      while(S[i]!=T[j])
	{
	  i++;
	}
      if(i!=n)onaji++;
    }

  printf("%d\n",onaji);

  return 0;
}

