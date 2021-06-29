#include <stdio.h>
#define N 10000

int serch(int,int,int);

int main(){
  int num,num2,i,S[N],SA[N],j;
  int cnt = 0;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&SA[i]);
  }
    for(i=0;i<num2;i++){
      for(j=0;j<num;j++){
	if(S[j] == SA[i]) {
	  cnt++;
	  break;
	}
    }
    }

  printf("%d\n",cnt);
  
  return 0;
}


