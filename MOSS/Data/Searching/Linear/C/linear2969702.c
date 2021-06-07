#include<stdio.h>
int search(int[], int, int);

int main(){
  int i, n, q, key, C=0;
  int S[10000], T[500];

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);

  for( i = 0 ; i < q ; i++ ){
    scanf("%d", &T[i]);
    if( search(S, n, T[i])) C++;
  }
  printf("%d\n", C);
  return 0;
}


int search(int S[], int n, int t){
  int i=0;
  S[n] = t;
  while( S[i] != t ) i++;
  return i != n;
}

