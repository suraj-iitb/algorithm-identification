#include <stdio.h>
#include <stdlib.h>

int main(){
  int count=0,N,x[100],hand,i,j;

  scanf("%d",&N);
  if(N<1 || N>100){
    printf("Please type 1 to 100.\n");
    exit(1);
  }
  
  for(i=0;i<N;i++){
    scanf("%d",&x[i]);
    if(x[i]<0 || x[i]>100){
      printf("Please type 0 to 100.\n");
      exit(2);
    }
  }
  for(j=0;j<N;j++){
    for(i=N-1;i>j;i--){
      if(x[i] <  x[i-1]){
	hand = x[i];
	x[i] = x[i-1];
	x[i-1] = hand;
	count++;
      }
    }
  }

  for(j=0;j<N;j++){
    if(j==N-1)printf("%d",x[j]);
    else printf("%d ",x[j]);
  }printf("\n%d\n",count);
  

  return 0;
}

