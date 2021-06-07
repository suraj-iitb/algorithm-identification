#include <stdio.h>

int main(){
  int i, k, n, q, m, l, r, S[100000], T[100000];
  k = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i< q; i++){
    l = 0;
    r = n;
    while(l < r){
    m = (l + r)/2;
    if(T[i] == S[m]){
      k++;
      break;
    }
    else if(T[i] < S[m]) r = m;
    else if(T[i] > S[m]) l = m + 1;
    }
  }

  printf("%d\n", k);
  
  return 0;
}
