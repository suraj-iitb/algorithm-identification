#include <stdio.h>
#include <stdlib.h>
int linearsearch(int, int *, int);
int main(){
  int n, q, S[10000], T;
  int i, num, count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T);
    num = linearsearch(T, S, n);
    if(num == 1)count++;
  }
  printf("%d\n",count);
  return 0;
}

int linearsearch(int T, int S[], int n){
  int i = 0;
  while(T != S[i]){
    i++;
    if(i == n)return 0;
  }
  return 1;
}

