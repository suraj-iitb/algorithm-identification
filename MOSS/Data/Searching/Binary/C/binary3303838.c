#include<stdio.h>
int A[100000000];
int n;

int binarySearch(int);

int main()
{
  int i,q,k,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&k);
      if(binarySearch(k)==1)count++;
    }
  printf("%d\n",count);
  return 0;
}
  
int binarySearch(int key)
{
  int  left = 0;
  int right = n;
  int mid;
  while (left < right)
    {
      mid = (left + right) / 2;
      if( A[mid] == key)return 1;
      if( key > A[mid]) left = mid+1;
      else if(key<A[mid]) right = mid;
    }
  return 0;
}

