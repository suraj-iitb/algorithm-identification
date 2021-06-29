#include<stdio.h>
#define N 100000
int linearSearch(int,int[]);

int q,n;

int main()
{
  int S[N],T[N],i,j,cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  
  scanf("%d",&q);

  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
    }

  for(i=0;i<q;i++)
    {
      if(linearSearch(T[i],S) == 1)cnt++;
    }

  printf("%d\n",cnt);
  
  return 0;
}

int linearSearch(int key,int S[])
{
  int i=0;

  while(S[i] != key)
    {
      i++;
      if(i == n)return 0;
    }
  return 1;
}

