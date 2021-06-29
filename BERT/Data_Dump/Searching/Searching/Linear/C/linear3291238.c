#include<stdio.h>

#define nMAX 10000
#define qMAX 500
#define FOUND 1
#define NOT_FOUND 0

int linerSearch(int *,int,int);

int main()
{
  int n,S[nMAX],q,T[qMAX],i,count=0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&S[i]);
    }

  scanf("%d",&q);

  for(i = 0 ; i < q ; i++)
    {
      scanf("%d",&T[i]);
    }

  for(i = 0 ; i < q ; i++)
    {
      if(linerSearch(S,T[i],n)) count++;
    }

  printf("%d\n",count);
  
  return 0;
}

int linerSearch(int *S,int key,int n)
{
  int i;

  for(i = 0 ; i < n ; i++)
    {
      if(S[i] == key) return FOUND;
    }
  return NOT_FOUND;
}

