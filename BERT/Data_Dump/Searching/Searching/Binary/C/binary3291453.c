#include<stdio.h>

#define nMAX 100000
#define qMAX 50000
#define FOUND 1
#define NOT_FOUND 0

int binarySearch(int *,int,int);

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
      if(binarySearch(S,T[i],n)) count++;
    }

  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int *S,int key,int n)
{
  int left,right,mid;

  left = 0;
  right = n;

  while(left < right)
    {
      mid = (left + right) / 2;

      if(S[mid] == key) return FOUND;

      else if(key < S[mid]) right = mid;

      else left = mid + 1;
    }

  return NOT_FOUND;
}

