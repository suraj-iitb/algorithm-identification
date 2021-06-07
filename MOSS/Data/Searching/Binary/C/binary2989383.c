#include<stdio.h>
int BSearch(int *,int,int);

int BSearch(int *S,int key,int n)
{
  int left=0,right=n,mid;
  while( left < right )
    {
      mid = (left+right)/2;
      if( S[mid] == key )
	return 1;
      else if( key < S[mid] )
	right = mid;
      else
	left = mid +1;
    }
  return 0;
}
  
int main()
{
  int i,n,q,key,count=0;
  int S[100000];

  scanf("%d",&n);
  for( i=0;i < n;i++)
      scanf("%d",&S[i]);

  scanf("%d",&q);
  for( i=0;i < q;i++)
    {
      scanf("%d",&key);
      count += BSearch(S,key,n);
    }

  printf("%d\n",count);
  return 0;
}

