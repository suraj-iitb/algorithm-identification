#include <stdio.h>

#define S_MAX 100000
#define T_MAX 1000

int main(){
  int S[S_MAX], T[T_MAX];
  int n, q, i, j, num=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0 ; i < q ; i++){
    for(j = 0 ; j < n ; j++){
      if(S[j] == T[i]){
        num++;
        break;
      }
    }
  }

  printf("%d\n", num);
  
  
  return 0;
}

