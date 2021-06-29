#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct X{
  char suit;
  int value;
};

struct X L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct X A[], int n, int left, int mid, int right ){
  int i,j,k;
  int n1 = mid -left,n2 = right - mid;
  for( i = 0 ; i < n1 ; i++ )L[i] = A[left + i];
  for( i = 0 ; i < n2 ; i++ )R[i] = A[mid + i];

  L[n1].value = SENTINEL;
  R[n2].value = SENTINEL;
  i = 0;
  j = 0;
  for( k = left ; k < right ; k++ ){
    if( L[i].value <= R[j].value ){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void mergeSort( struct X A[], int n, int left, int right ){
  int mid;
  if( left + 1 < right ){
    mid = ( right + left ) / 2;
    mergeSort( A, n, left, mid );
    mergeSort( A, n, mid ,right );
    merge( A, n, left, mid, right );
  }
}

int partition( struct X A[], int n, int p, int r ){
  int i,j;
  struct X t,x;
  x = A[r];
  i = p - 1;
  for( j = p ; j < r ; j++ ){
    if(A[j].value <= x.value ){
      i++;
      t = A[i];
      A[i]= A[j];
      A[j] = t;
    }
  }
  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;

  return i + 1;
}

void quick( struct X A[], int n, int p, int r ){
  int q;
  if ( p < r){
    q = partition( A, n, p, r );
    quick( A, n, p, q - 1 );
    quick( A, n, q + 1, r );
  }
}

int main( void ){
  int n, i, a;
  struct X A[MAX], B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%s %d", S, &a);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = a;
  }
  mergeSort( A, n, 0, n );
  quick( B, n, 0, n - 1 );

  for( i = 0 ; i < n ; i++ ){
    if ( A[i].suit != B[i].suit )stable = 0;
  }

  if( stable == 1 )printf("Stable\n");
  else printf("Not stable\n");
  for( i = 0 ; i < n ; i++ ){
    printf("%c %d\n",B[i].suit,B[i].value);
  }

  return 0;
}