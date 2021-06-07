#include<stdio.h>

int main(){
  int N, M, i, j, k = 0, S[10000], T[500];
  
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &S[i]);
  }
  
  scanf("%d", &M);
  for(i = 0; i < M; i++){
    scanf("%d", &T[i]);
  }
  
  /*N(S)??§?????????M(T)??¨??????*/
  if(N >= M){
    for(i = 0; i < M; i++){
      for(j = 0; j < N; j++){
        if(T[i] == S[j]){
          k += 1; 
          break;
        }
      }
    }
  }
  
  else{/*M(T)??§?????????N(S)??¨??????*/
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
        if(S[i] == T[j]){
          k += 1;
          break;
        }
      }
    }
  }
  
  printf("%d\n",k);
  
  return 0;
}
