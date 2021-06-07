#include <stdio.h>
int main(){
  int S[100000],T[500],S_num,T_num,cnt = 0,tmp = -1;
  scanf("%d",&S_num);
  for(int i = 0; i < S_num; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&T_num);
  for(int i = 0; i < T_num; i++){
    scanf("%d",&T[i]);
  }
  for(int i = 0; i < T_num;i++){
    for(int j  = 0; j < S_num; j++){
      if(T[i] == S[j]){
	if(S[j] != tmp){
	  cnt++;
	  tmp = S[j];
	}
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}

