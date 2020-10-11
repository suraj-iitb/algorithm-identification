#include <stdio.h>
#include <stdlib.h>

int *S, n, count=0, *L, *R;
void merge(int, int, int);
void mergeSort(int, int);


int main() {
  int i;

  scanf( "%d" , &n );
  S = (int *)malloc((n+1) * sizeof(int));
  for( i=0; i<n; i++ ) scanf( "%d" , &S[i] );
  mergeSort(0, n);
  for( i=0; i<(n-1); i++ ) printf( "%d " , S[i] );
  printf( "%d\n%d\n" , S[n-1] , count );
  
  return 0;
}


void merge(int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid, i, j=0, k;

  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));
  for ( i=0; i<n1; i++ ) L[i] = S[left+i];
  for ( i=0; i<n2; i++ ) R[i] = S[mid+i];
  L[n1] = R[n2] = 1000000001;
  i = 0;
  for ( k=left; k<right; k++ ) {
    if ( L[i] <= R[j] ) {
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


