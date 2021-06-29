#include<stdio.h>

int A[1000000];
int n;

int search(int key);

int main(){
  int i, q, k, cnt = 0;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  for ( i = 0; i < q; i++ ){
    scanf("%d", &k);
    if ( search(k) ) cnt++;
  }
  printf("%d\n", cnt);

  return 0;
}

int search(int key){
  int l = 0;
  int r = n;
  int m;
  while( l < r ){
    m = (l + r ) /2;
    if ( key == A[m] ) return 1;
    if ( key > A[m] ) l = m+1;
    else if ( key < A[m] ) r = m;
  }
  return 0;
}

