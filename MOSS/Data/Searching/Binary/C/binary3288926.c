#include <stdio.h>
#include <stdlib.h>
int BS(int, int *, int);
int main(){
  int n, q, S[100000], T;
  int i, num, count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T);
    num = BS(T, S, n);
    if(num == 1)count++;
  }
  printf("%d\n",count);
  return 0;
}
int BS(int T, int S[], int n){
  int L, R, M;
  L = 0;
  R = n;
  while(L < R){
    M = (L + R) / 2;
    if(S[M] == T)return 1;
    else if(T < S[M])R = M;
    else L = M +1;
  }
  return 0;
}

