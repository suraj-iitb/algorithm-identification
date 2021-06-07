#include <stdio.h>
#define MAX 100000

int binarySearch(int);

int S[MAX], n;

int main() {
  int q, key;
  int sum = 0;
  int i;

  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &S[i]);

  scanf("%d", &q);
  for( i = 0; i < q; i++ ) {
    scanf("%d", &key);
    if( binarySearch(key) ) sum++;
  }

  printf("%d\n", sum);
  
  return 0;
}

int binarySearch(int key) {
  int left = 0, right = n, mid;
  while ( left < right ) {
    mid = (left + right) / 2;
    if ( S[mid] == key ) return 1;
    else if( S[mid] > key ) right = mid;
    else if( S[mid] < key ) left = mid + 1;
  }
  return 0;
}
