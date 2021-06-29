#include<stdio.h>

int search(int S[], int n, int T[], int j){
  int i = 0;
  S[n] = T[j];
  while ( S[i] != T[j] ) i++;
  return i != n;
}

int main(){

  int n, q, C, j;
  int S[10000], T[500];
  C = 0;

  scanf("%d", &n);
  for ( j = 0; j < n; j++ ) scanf("%d", &S[j]);

  scanf("%d", &q);
  for ( j = 0; j < q; j++ ){
    scanf("%d", &T[j]);
    if ( search(S, n, T, j) ) C++;
  }

  printf("%d\n", C);

  return 0;
}
