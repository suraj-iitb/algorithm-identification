#include <stdio.h>
#define NMAX 100

int main(void){

  int i,j,N,inp[NMAX],temp,cnt = 0;
  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%d",&inp[i]);
  }

  for(i = 0;i < N;i++){
    for(j = N - 1;j >= i + 1;j--){
      if(inp[j] < inp[j - 1]){
	temp = inp[j];
	inp[j] = inp[j - 1];
	inp[j - 1] = temp;
	cnt++;
      }
    }
  }
  for(i = 0;i < N;i++){
    if(i == N - 1){
      printf("%d",inp[i]);
    }else{
      printf("%d ",inp[i]);
	}
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

