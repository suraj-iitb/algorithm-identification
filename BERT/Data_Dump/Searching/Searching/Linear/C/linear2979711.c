#include<stdio.h>
#define N 1000000

int main()
{
  int i,j,key,n,q,cnt=0,S[N],T[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  i = 0;
  while(i<q)
    {
      scanf("%d",&T[i]);
      for(j=0;j<i;j++)
	if(T[i] == T[j]) break;
      if(i == j) i++;
    }

  for(i=0;i<q;i++)
    {
      j = 0;
      key = T[i];
      while(key != S[j])
	{
	  j++;
	  if(j == n) break;
	}
      if(j != n) cnt++;
    }

  printf("%d\n",cnt);
    return 0;
}

