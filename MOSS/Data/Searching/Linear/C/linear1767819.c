#include <stdio.h>
#define n 10000
#define q 5000

int main(){
  
  int S[n];
  int T[q];
  int U[n];

  int sNum,tNum;

  int i,j,k;

  int c = 0;

  int flag;

  scanf("%d",&sNum);

  for(i = 0; i < sNum; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&tNum);

  for(i = 0; i < tNum; i++){
    scanf("%d",&T[i]);
  }



  for(i = 0; i < sNum; i++){
    for(j = 0; j < tNum; j++){
      flag = 0;
      if(S[i] == T[j]){
	for(k = 0; k < c; k++){
	  if(U[k] == S[i]){
	    flag = 1;
	    break;
	  }
	}
	if(flag == 0){
	  U[c] = S[i];
	  c++;
	}
      }
    }
  }

  printf("%d\n",c);

  return 0;
}
