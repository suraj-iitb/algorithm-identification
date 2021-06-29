#include<stdio.h>

int serch(int,int,int);


int main(){
  int i, n, A[10000], q,k,num = 0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  scanf("%d", &q);
  for ( i = 0; i < q; i++ )
  {
    scanf("%d", &k);
    if ( search(A, n, k) ) num++;
  }
  printf("%d\n", num);

  return 0;
}

int search(int A[], int n, int k)
{
  int i;
  for ( i = 0; i < n; i++ )
  {
    if ( A[i] == k ) return 1;
  }
  return 0;
}
