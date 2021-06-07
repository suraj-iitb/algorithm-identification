#include <stdio.h>
#define MAX 10001

int linerSearch(int);

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
    if( linerSearch(key) ) sum++;
  }

  printf("%d\n", sum);
  
  return 0;
}

int linerSearch(int key) {
  int i = 0;
  S[n] = key;
  while( S[i] != key ) i++;
  if( i == n ) return 0;
  
  return 1;
}
