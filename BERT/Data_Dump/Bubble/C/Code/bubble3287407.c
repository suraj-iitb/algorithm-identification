#include <stdio.h>
#define N_max 100

int main(){
  int i,j,change,N,array[N_max],count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&array[i]);
  }
  
  i=0;
  while(1){
    for(j=N-1;j>=i+1;j--){
      if(array[j]<array[j-1]){
	change = array[j];
	array[j] = array[j-1];
	array[j-1] = change;
	count++;
      }
    }
    i++;
    if(i==N){
      break;
    }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[N-1]);
  printf("%d\n",count);

  return 0;
}

