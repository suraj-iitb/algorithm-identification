#include<stdio.h>
#include<stdlib.h>

void merge( long int *, int, int, int );
int mergeSort( long int *, int, int );

int count=0;

int main()
{
  int i, n;
  long int *S;

  scanf("%d", &n);
  S = malloc( n * sizeof(long int));
  for( i=0; i<n; i++ ) scanf("%d", &S[i]);

  *S = mergeSort( S, 0, n );

  for( i=0; i<n-1; i++ ) printf("%d ", S[i]);
  printf("%d\n", S[n-1]);

  printf("%d\n", count);

  return 0;
}



void merge( long int *A, int left, int mid, int right )
{
  int i, j, k, n1, n2, *L, *R;
  long int INFTY=10000000000;
  
  n1 = mid - left;
  n2 = right - mid;

  L = malloc( (n1+1) * sizeof(int));
  R = malloc( (n2+2) * sizeof(int));
  
  for( i=0; i<n1; i++ ) L[i] = A[left + i];
  for( i=0; i<n2; i++ ) R[i] = A[mid + i];
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
    
  for( k=left; k<right; k++ )
    {
      if( L[i] <= R[j] )
	{
	  A[k] = L[i];
	  i = i + 1;
	}
      else
	{
	  A[k] = R[j];
	  j = j + 1;
	}
      count++;
    }
}

      
int mergeSort( long int *A, int left, int right )
{
  int mid;
  
  if( left+1 < right )
    {
      mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }

  return *A;
}

