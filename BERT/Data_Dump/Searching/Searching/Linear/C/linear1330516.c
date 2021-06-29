#include <stdio.h>
#define N 500
#define M 10000

main(){
  int i, j, n, q, S[M], T[N], C=0;
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  } 

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(S[j] == T[i]){
    C++;
    break;
      }
    }
  }
  printf("%d\n", C);
  return 0;
}
