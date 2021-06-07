#include <stdio.h>

int main(void){

  int i,j,n1,n2,key,cnt=0;
  int S[10000],T[500];

  scanf("%d",&n1);
  for(i = 0;i < n1;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&n2);
  for(i = 0;i < n2;i++){
    scanf("%d",&T[i]);
  }

  for(i = 0;i < n2;i++){
    S[n1] =  T[i];
    j = 0;
    while(S[j] != S[n1]){
      j++;
    }
    if(j != n1){
      cnt++;
    }
		
  }
  
  printf("%d\n",cnt);

  return 0;
}


