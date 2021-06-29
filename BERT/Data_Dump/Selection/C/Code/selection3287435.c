#include <stdio.h>

#define N_max 100

int main(){
  int i,j,minj,change,N,array[N_max],count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(array[j]<array[minj]){
	minj = j;
      }
    }
    if(array[i]==array[minj]){
      continue;
    }
    change = array[i];
    array[i] = array[minj];
    array[minj] = change;
    count++;
  }

  for(i=0;i<N-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[N-1]);
  printf("%d\n",count);
  
  return 0;
}

