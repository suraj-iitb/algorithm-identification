#include<stdio.h>
#define N 100000

int BinarySearch(int,int[]);

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
      if(BinarySearch(T[i],S) == 1)cnt++;
    }

  printf("%d\n",cnt);

  
  return 0;
}

int BinarySearch(int key,int S[])
{
  int left=0,right=n,mid;
  while( left < right)
  { 
    mid = (left + right) / 2;
    if (S[mid] == key) return 1;
    
    else if (key < S[mid]) right = mid;
    
    else left = mid + 1;
  }
  return 0;
}

