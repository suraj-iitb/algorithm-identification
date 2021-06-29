#include <stdio.h>

#define N 500000
#define MAX 1000

int L[N/2+2], R[N/2+2];
int count = 0;

void mergeSort( int *, int, int );
void merge( int *, int, int, int );

int main()
{
  int S[N];
  int i,n;
  int left, right;

  scanf("%d",&n);

  for( i = 0; i < n; i++ )
    scanf("%d",&S[i]);

  right = n;
  left = 0;

  mergeSort( S, left, right );

  for( i = 0; i < n; i++ )
    {
      if( i < n-1 )
	printf("%d ",S[i]);
      else
	printf("%d\n",S[i]);
    }

  printf("%d\n",count);

  return 0;
}

void merge( int S[], int left, int mid, int right )
{
  int i,j,k;
  int n1, n2;

  n1 = mid - left;
  n2 = right - mid;

  for( i = 0; i < n1; i++ )
    L[i] = S[left+i];
  for( i = 0; i< n2; i++ )
    R[i] = S[mid+i];

  L[n1] = MAX*MAX*MAX;
  R[n2] = MAX*MAX*MAX;

  i = 0;
  j = 0;

  for( k = left; k < right; k++ )
    {
      count++;
      
      if( L[i] <= R[j] )
	{
	  S[k] = L[i];
	  i++;
	}
      else
	{
	  S[k] = R[j];
	  j++;
	}
    }
}

void mergeSort( int S[], int left, int right )
{
  int mid;
  
  if( left+1 < right )
    {
      mid = (left+right) / 2;
      mergeSort( S, left, mid );
      mergeSort( S, mid, right );
      merge( S, left, mid, right );
    }
}
      

  

