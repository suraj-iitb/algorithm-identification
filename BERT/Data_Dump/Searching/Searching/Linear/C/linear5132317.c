#include <stdio.h>

#define MAX_N 10000

int main(){
  int a=0,b=1,c=2,d=3;
  for (a = 0; a < 700; a++) {
    c = a + d;
    a = a + b;
  }
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

