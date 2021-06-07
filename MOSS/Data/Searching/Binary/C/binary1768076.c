#include<stdio.h>
#include<stdlib.h>
#define nmax 100000
#define qmax 50000

int binarySearch(int);
int S[nmax],n;
int count;
int judge[qmax];

int main()
{
  int q;
  int T[qmax],i,flag,j,x;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ )
    {
      scanf("%d",&S[i]);
    }

  scanf("%d",&q);

  for( i = 0 ; i < q ; i++ )
    {
      scanf("%d",&T[i]);   
    x = binarySearch(T[i]);
      if( x != -1 ) count++;
    }

  printf("%d\n",count);

  return 0;
}


int binarySearch(int key)
{
  int left,right,mid;
  left = 0;
  right = n;
  while( left < right )
    {
      mid = (left + right)/2;
      if( S[mid] == key )
	return mid;    
      else if( key < S[mid] )
	right = mid;
      else 
	left = mid + 1;
    }
  return -1;

}
