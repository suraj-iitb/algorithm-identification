#include<stdio.h>
main(){
  int n, q, S[10000], T[500], i, j, key, c=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  for(i = 0; i < q; i++){
    key = T[i];
   S[n] = key;
   j = 0;
    while(S[j] != key){
      j++;
    }
    if(j != n){
      c++;
    }
  }
  printf("%d\n", c);
  return 0;
}
