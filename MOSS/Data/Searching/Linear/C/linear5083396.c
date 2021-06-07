#include <stdio.h>

int main(void){
  int i,j;
  int count = 0;
  int S_num;
  int T_num;
  int S[10000],T[500];

  scanf("%d",&S_num);
  for(i = 0; i < S_num; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&T_num);
  for(i = 0; i < T_num; i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<T_num;i++){
    for(j=0;j<S_num;j++){
      if(S[j]==T[i]){
	count++;
      break;
      }
    }
  }

  printf("%d\n",count);
}

