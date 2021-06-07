#include <stdio.h>
#define N 10000
#define Q 500
#define NOT_FOUND 0

int linearSearch(int *A, int n, int v){
  int i=0;
  A[n] = v;
  while(A[i] != v){
    i++;
    if(i == n) return NOT_FOUND;
  }
  // printf("%d ",A[i]);
  return 1;
}

int main(){
  int i,n,q,c=0;
  int S[N];
  int T[Q+1];

  // input
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d ", &S[i]);
  scanf("%d",&q);
  for(i=0; i<q; i++) scanf("%d ", &T[i]);

  // search
  for(i=0; i<q; i++) c = c+linearSearch(S,n,T[i]);

  // output
  printf("%d\n", c);

  return 0;
}
