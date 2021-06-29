#include <stdio.h>

int selectSort(int A[], int N)
{
  int t,j, i=0, sw=0,mini;

  for ( i = 0; i < N; i++ ){
    mini = i;
    for ( j = i; j < N; j++ ){
      if ( A[j] < A[mini] ) mini = j;
    }
    if ( i != mini ) {
      sw++;
      t = A[i]; A[i] = A[mini]; A[mini] = t;
    }
  }
  return sw;
}


void print(int A[], int N, int sw){
  int i;
  for ( i = 0; i < N; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);
}

int main( void )
{
  int A[100], n, i, sw=0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  sw=selectSort(A,n);

  print(A,n,sw);
  
  return 0;
}

