#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND 0

int binarySearch(int* A, int n, int key){
  int l=0,m,r=n;
  while(l<r){
    m = (l+r) / 2;
    if(key == A[m]) return 1;
    if(key >  A[m]) l = m+1;
    else if(key < A[m]) r = m;
  }
  return NOT_FOUND;
}

int main(){
  int i,c=0,n,q;
  int *S;
  int *T;

  // input and allocation
  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++) scanf("%d ", &S[i]);
  scanf("%d", &q);
  T = (int *)malloc(sizeof(int) * q);
  for(i=0; i<q; i++) scanf("%d ", &T[i]);

  // search
  for(i=0; i<q; i++) c = c+binarySearch(S, n, T[i]);

  // output
  printf("%d\n", c);

  return 0;
}
