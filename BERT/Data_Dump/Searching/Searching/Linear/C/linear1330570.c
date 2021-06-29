#include<stdio.h>

int main(){

  int S[1000000];
  int T[1000000];
  int Scount;
  int Tcount;
  int count;
  int i,j;

  scanf("%d",&Scount);

  for(count = 0;count < Scount;count++){
    scanf("%d",&S[count]);
  }

  scanf("%d",&Tcount);

  for(count = 0;count < Tcount;count++){
    scanf("%d",&T[count]);
  }
  count = 0;

  for(i = 0;i < Tcount;i++){
    for(j = 0;j < Scount;j++){
      if(S[j] == T[i]){
	count++;
	break;
}
    }
  }
  printf("%d\n",count);
  return 0;
}
