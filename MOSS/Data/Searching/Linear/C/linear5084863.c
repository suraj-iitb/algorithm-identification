#include <stdio.h>

#define N 10000
#define M 500

int linear(int,int *,int);

int main()
{
  int n,q,s[N],t[M],i,key,x=0;

  scanf("%d",&n);
  for(i=0 ; i < n ; i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i < q ; i++)
    scanf("%d",&t[i]);

  for(i=0 ; i < q ; i++)
    {
      key=linear(n,s,t[i]);
      if(key == 1) x++;
    }
  printf("%d\n",x);

  return 0;
}
int linear(int n,int *s,int y)
{
  int i=0;
  s[n] = y;
  while(s[i] != y)
    i++;
  if (i == n) return -1;

  return 1;
}
