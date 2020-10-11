#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char mark;
  int value;
} Card;

Card *S, *L, *R;
int N, count=0;
void merge(int, int, int);
void mergeSort(int, int);
int partition(Card *, int, int);
Card *quicksort(Card *, int, int);


int main() {
  int i, stable=1;
  Card *IN, *OUT;
  
  scanf( "%d" , &N );
  IN = OUT = malloc(N * sizeof(Card));
  S = malloc((N+1) * sizeof(Card));
  for ( i=0; i<N; i++ ) {
    scanf( " %c" , &(S[i].mark) );
    scanf( "%d" , &(S[i].value) );
    OUT[i] = S[i];
  }

  OUT = quicksort(OUT, 0, N-1);
  mergeSort(0, N);
  for ( i=0; i<N; i++ ) if ( S[i].mark != OUT[i].mark ) stable = 0;
  if ( stable == 1 ) printf( "Stable\n" );
  else printf( "Not stable\n" );
  for ( i=0; i<N; i++ ) printf( "%c %d\n" , OUT[i].mark , OUT[i].value );
  
  return 0;
}


void merge(int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid, i, j=0, k;

  L = malloc((n1+1) * sizeof(Card));
  R = malloc((n2+1) * sizeof(Card));
  for ( i=0; i<n1; i++ ) L[i] = S[left+i];
  for ( i=0; i<n2; i++ ) R[i] = S[mid+i];
  L[n1].value = R[n2].value = 1000000001;
  i = 0;
  for ( k=left; k<right; k++ ) {
    if ( L[i].value <= R[j].value ) {
      S[k] = L[i];
      i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int left, int right) {
  int mid, i;

  if ( (left+1) < right ) {
    mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int partition(Card *A, int p, int r) {
  int x, i, j;
  Card temp;
  
  x = A[r].value;
  i = p-1;
  for ( j=p; j<r; j++ )
    if ( A[j].value <= x ) {
      i = i+1;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  
  return i+1;
}

Card *quicksort(Card *A, int p, int r) {
  int q;
  
  if ( p < r ) {
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }

  return A;
}

