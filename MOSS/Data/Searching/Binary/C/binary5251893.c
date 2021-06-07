#include<stdio.h>

int binary_search(int* A, int size, int n){
  int l = 0, r = size;
  while(l < r){
    int c = (l+r)/2;
    if(A[c] == n) return 1;
    if(A[c] < n) l = c+1;
    else r = c;
  }
  return 0;
}

int main(){
  int n, q, cnt = 0;
  scanf("%d",&n);
  int S[n];
  for(int i = 0; i < n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(int i = 0; i < q; i++) scanf("%d",&T[i]);
  for(int i = 0; i < q; i++) cnt += binary_search(S, n, T[i]);
  printf("%d\n", cnt);
  return 0;
}

