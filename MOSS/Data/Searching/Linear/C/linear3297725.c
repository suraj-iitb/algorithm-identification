#include<stdio.h>
#define X 10000
int main(){
  int S[X],T[X],N,Q,n,q,count=0;
  scanf("%d",&N);
  for(n = 0 ; n < N ; n++) scanf("%d",&S[n]);
  scanf("%d",&Q);
  for(q = 0 ; q < Q ; q++){
     scanf("%d",&T[q]);
    S[N]=T[q];
    for(n = 0 ; n < N ; n++){
      if(S[n] == S[N]){
	count++;
	break;
      }
      
    }

  }
  printf("%d\n",count);
  return 0;
}

