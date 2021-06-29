#include<stdio.h>

int A[1000000],n;

int Binary(int key)
{
  int Left=0;
  int Right=n;
  int Middle;

  while(Left<Right)
    {
      Middle=(Left+Right)/2;
      if(key==A[Middle]) return 1;
      if(key<A[Middle]) Right=Middle;
      else if(key>A[Middle]) Left=Middle+1;
    }
  return 0;
}

int main()
{
  int i,q,key,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(Binary(key)==1) cnt++;
    }
  printf("%d\n",cnt);

  return 0;
}
