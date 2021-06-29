#include<stdio.h>
#define A 100

main(){
  int array[A];
  int mini,tmp;
  int count=0;
  int N;
  int i,j;
  
  scanf("%d",&N);/*input includes an integer N*/
  
  for(i=1; i<=N; i++){
    scanf("%d",&array[i]);
  }
  
  for(i=1; i<=N; i++){
    mini = i;
    for(j=i; j<=N; j++){
      if(array[j]<array[mini]){
	mini=j; 
      }
    }
    if(i!=mini){
      tmp=array[i];
      array[i]=array[mini];
      array[mini]=tmp; 
      count++;
    }
  }
  
  for(i=1; i<=N; i++){
    printf("%d",array[i]);
    if(i < N){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  
  return 0;
}
