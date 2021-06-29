#include <stdio.h>

int main(){

  int S[10000], T[500], i, j, n, q, count = 0;

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
      //printf("%d %d\n", S[j], T[i]); 
      if(S[j] == T[i]){
	count++;
	break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
  
  

}

