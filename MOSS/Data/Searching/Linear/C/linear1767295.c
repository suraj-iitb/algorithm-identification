#include <stdio.h>

#define N 10001
#define Q 501

int linearSearch(int *, int, int);

int main(){
  int i, n, q, S[N], T[Q], cnt=0;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 1; i <= q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 1; i <= q; i++){
    if(linearSearch(S, n, T[i])) cnt++;
  }

  printf("%d\n", cnt);

  return 0;
}

int linearSearch(int *S, int n, int key){
  int i = 1;
  S[n + 1] = key;
  while(S[i] != key) i++;
  if(i == n + 1) return 0;
  return i;
}
