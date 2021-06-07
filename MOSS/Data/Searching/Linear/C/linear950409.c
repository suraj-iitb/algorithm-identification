#include<stdio.h>
#define N 10000
#define M 500


int main(void){
  int i, j, n, q, S[N], T[M], a, b, count=0;
  scanf("%d", &n);
  for(i=0; i<n ;i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i=0; i<q ;i++)  scanf("%d", &T[i]);

  for(i=0; i<n ;i++){
    for(j=0; j<q ;j++){
    
a = S[i];
    b = T[j];
    if(a == b) { count++; T[j] = -1; }
    }
  }
  printf("%d\n", count);
  return 0;
}
