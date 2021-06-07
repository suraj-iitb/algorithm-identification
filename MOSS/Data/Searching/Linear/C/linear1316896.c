#include <stdio.h>

#define MAX_N 10000

int main(){
  int N,Q,i,j,S[MAX_N],T,res = 0;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&Q);
  for(i = 0 ; i < Q ; i++){
    scanf("%d",&T);
    for(j = 0 ; j < N ; j++){
      if(T == S[j]){
        ++res;
        break;
      }
    }
  }
  printf("%d\n",res);
  return 0;
}
