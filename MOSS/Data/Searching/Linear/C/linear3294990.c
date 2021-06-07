#include <stdio.h>
#define N 100000000
#define NOT -1

int n,q,S[N],T[N];

int Linear(int key)
{
  int i = 0;

  while(S[i] != key)
    {
      i++;
      if(i == n) return NOT;
    }
  return i;
}

int main()
{
  int i,t = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0;i < q;i++) scanf("%d",&T[i]);

  for(i = 0;i < q;i++)
    {
      if(Linear(T[i]) != NOT) t++;
    }

  printf("%d\n",t);

  return 0;
}


