#include <stdio.h>
#include <stdlib.h>

#define INFTY 2147483647

int count;

void merge( int *a, int left, int mid, int right) {

  int *l, *r;
  int n1, n2;

  int i, j, k;

  n1 = mid - left;
  n2 = right - mid;
  
  l = (int *)malloc(sizeof(int) *(n1+1));
  r = (int *)malloc(sizeof(int) *(n2+1));

  for( i=0; i<n1; i++) {
    l[i] = a[left+i];
  }
  for( i=0; i<n2; i++) {
    r[i] = a[mid+i];
  }

  l[n1] = INFTY;
  r[n2] = INFTY;

  i=0;
  j=0;

  for( k=left; k<right; k++) {

    if( l[i] <= r[j]) {
      a[k] = l[i];
      i++;
    }
    else {
      a[k] = r[j];
      j++;
    }

    count++;

  }

  free(l);
  free(r);

}


void mergeSort( int *a, int left, int right) {

  int mid;

  if( left+1 < right) {
    mid = ( left + right)/2;
    mergeSort( a, left, mid);
    mergeSort( a, mid, right);
    merge( a, left, mid, right);
  }

}


int *makeIntArray( int n) { 

  int *a;
  int i;

  a = (int *)malloc(sizeof(int) *n);

  for( i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  return a; //配列ポインタ

}


int main() {

  int n;
  int *a;

  int i;


  scanf("%d", &n);
  a = makeIntArray( n );

  mergeSort( a, 0, n);

  for( i=0; i<n-1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[i], count);

  return 0;

}
