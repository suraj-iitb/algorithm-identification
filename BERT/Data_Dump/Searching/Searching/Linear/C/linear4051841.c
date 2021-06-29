#include<stdio.h>

int search(int A[], int n, int key);

int main(){
  int i, n, A[10000], q, key, cnt = 0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  scanf("%d", &q);
  for ( i = 0; i < q; i++ ){
    scanf("%d", &key);
    if ( search(A, n, key) ) cnt++;
  }
  printf("%d\n", cnt);


  return 0;
}

int search(int A[], int n, int key){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( A[i] == key ) return 1;
  }
  return 0;
}

