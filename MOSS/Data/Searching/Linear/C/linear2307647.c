#include <stdio.h>
#define N 10000
#define Q 500

int main()
{
  int S[N], T[Q], i, j, n, q, count=0;

  scanf("%d", &n);
  for( i = 0 ; i < n ; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for( i = 0 ; i < q ; i++){
    scanf("%d", &T[i]);
  }
  
  for( i = 0 ; i < q ; i++){
    j = 0;
    S[n] = T[i];
    while(S[j] != T[i]){
      j++;
    }
    if(j != n){
      count++;
    }
  }

  printf("%d\n", count);
  
  return 0;
}
