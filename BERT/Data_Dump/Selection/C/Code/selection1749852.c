#include<stdio.h>
 
int main(){
  int i,j,x[100],N,minj,count=0,tmp;
 
  scanf("%d",&N);

  for(i=0;i<N;i++){

    scanf("%d",&x[i]);
  
  }
 
  for(i=0;i<N;i++){
    minj = i;
    for(j = i;j<N;j++){
      if(x[j]<x[minj]){
	minj = j;
      }
    }
    if(i != minj){
      tmp = x[i];
      x[i] = x[minj];
      x[minj] = tmp;
      count++;
    }
  }
 
  for(i=0;i<N-1;i++){
    
    printf("%d ",x[i]);

  }
  
    printf("%d\n%d\n",x[N-1],count);

  
 
  return 0;
}
