#include<stdio.h>
int binarySearch(int);
int A[100000], n;
int main() {
  int i, a, b, count = 0;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ )
    scanf("%d", &A[i]);

  scanf("%d", &a);
  for ( i = 0; i < a; i++ ) {
    scanf("%d", &b);
    if ( binarySearch( b ) ) count++;
  }
  printf("%d\n", count);

  return 0;
}

int binarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;
  while ( left < right ) {
    mid = (left + right) / 2;
    if ( key == A[mid] ) return 1;
    if ( key > A[mid] ) left = mid + 1;
    else if ( key < A[mid] ) right = mid;
  }
  return 0;
}


