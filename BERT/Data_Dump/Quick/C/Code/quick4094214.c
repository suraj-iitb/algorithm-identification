#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INFTY 1000000000

void quickSort( char *, int *, int, int );
int partition( char *, int *, int, int );
void merge( char *, int *, int, int, int );
void mergeSort( char *, int *, int, int );

int main()
{
  int i, n, *A, *B;
  char *M, *MM;
    
  scanf("%d", &n);
  A = malloc( n * sizeof(int));
  M = malloc( n * sizeof(char));
  B = malloc( n * sizeof(int));
  MM = malloc( n * sizeof(char));
  for( i=0; i<n; i++ )
    {
      scanf("%*c%c%d", &M[i], &A[i]);
      MM[i] = M[i];
      B[i] = A[i];
    }
  
  quickSort( M, A, 0, n-1 );
  mergeSort( MM, B, 0, n );

  if( strcmp(M,MM)==0 ) printf("Stable\n");
  else printf("Not stable\n");
  
  for( i=0; i<n; i++ ) printf("%c %d\n", M[i], A[i]);

  return 0;
}



void quickSort( char *M, int *A, int p, int r )
{
  int q;

  if( p < r )
    {
      q = partition( M, A, p, r );
      quickSort( M, A, p, q-1 );
      quickSort( M, A, q+1, r );
    }
}


int partition( char *M, int *A, int p, int r )
{
  int i, j, x, temp1;
  char temp2;

  x = A[r];
  i = p-1;

  for( j=p; j<r; j++ )
    {
      if( A[j] <= x )
	{
	  i = i + 1;
	  temp1 = A[i];
	  A[i] = A[j];
	  A[j] = temp1;

	  temp2 = M[i];
	  M[i] = M[j];
	  M[j] = temp2;
	  
	}
    }

  temp1 = A[i+1];
  A[i+1] = A[r];
  A[r] = temp1;

  temp2 = M[i+1];
  M[i+1] = M[r];
  M[r] = temp2;

  return i+1;
}

 
void merge( char *MM, int *B, int left, int mid, int right )
{
  int i, j, k, n1, n2, *L, *R;
  char *LM, *RM;
  
  
  n1 = mid - left;
  n2 = right - mid;

  L = malloc( (n1+1) * sizeof(int));
  R = malloc( (n2+1) * sizeof(int));
  LM = malloc( (n1+1) * sizeof(char));
  RM = malloc( (n2+1) * sizeof(char));
  
  for( i=0; i<n1; i++ )
    {
      L[i] = B[left + i];
      LM[i] = MM[left + i];
    }
  
  for( i=0; i<n2; i++ )
    {
      R[i] = B[mid + i];
      RM[i] = MM[mid + i];
    }
  
  L[n1] = INFTY; 
  R[n2] = INFTY;
  i = 0;
  j = 0;
    
  for( k=left; k<right; k++ )
    {
      if( L[i] <= R[j] )
	{
	  B[k] = L[i];
	  MM[k] = LM[i];
	  i = i + 1;
	}
      else
	{
	  B[k] = R[j];
	  MM[k] = RM[j];
	  j = j + 1;
	}
    }
}

      
void mergeSort( char *MM, int *B, int left, int right )
{
  int mid;
  
  if( left+1 < right )
    {
      mid = (left + right)/2;
      mergeSort(MM, B, left, mid);
      mergeSort(MM, B, mid, right);
      merge(MM, B, left, mid, right);
    }

}

