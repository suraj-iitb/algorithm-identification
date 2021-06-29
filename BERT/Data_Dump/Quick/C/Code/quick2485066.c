#include<stdio.h>
#define N 100000

struct Card{
  char c;
  int n, index;
};

int Partition( struct Card A[], int p, int r ){
  int x;
  int i,j;
  struct Card c;
  x = A[r].n;
  i = p - 1;
  for( j = p; j < r; j++ ){
    if( A[j].n <= x){
      i++;
      c = A[i];
      A[i] = A[j];
      A[j] = c;
    }
  }
  c = A[i+1];
  A[i+1] = A[r];
  A[r] = c;

  return i+1;
}

void QuickSort( struct Card A[], int p, int r ){
  int q;
  if( p < r ){
    q = Partition( A, p, r );
    QuickSort( A, p, q-1 );
    QuickSort( A, q+1, r );
  }
}

int isStable( struct Card A[], int n ){
  int i;
  for( i = 1; i < n; i++ ){
    if( A[i-1].n == A[i].n ){
      if( A[i-1].index > A[i].index ){
    return 0;
      }
    }
  }
  return 1;
}

int main(){
  int n, i=0;
  struct Card A[N];

  scanf("%d", &n);

  while(i<n){
    scanf(" %c %d", &A[i].c, &A[i].n);
    A[i].index = i;
    i++;
  }

  QuickSort( A, 0, n-1 );

  if( isStable(A, n) == 1 ){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  for( i = 0; i < n; i++ ){
    printf("%c %d\n", A[i].c, A[i].n);
  }
  return 0;
}
