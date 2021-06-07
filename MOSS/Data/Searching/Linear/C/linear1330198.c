#include <stdio.h>

int lenearSearch(int *, int);
int n, q;

int main(){

  int i, count=0;
  int S[10000], T[500];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
    if(lenearSearch(S, T[i]) == 1) count++;
  }

  printf("%d\n", count);

  return 0;
}

int lenearSearch(int *A, int key){
  int i=0;

  A[n] = key;

  while(A[i] != key) i++;
  if(i == n)
    return 0;
  return 1;
}
