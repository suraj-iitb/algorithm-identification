
#include<stdio.h>
#define A 100

main(){
  int length[A];
  int change=0;
  int N;
  int count=0;
  int i,j;
  
  scanf("%d",&N);/*input includes an integer N*/
  
  for(i=1; i<=N; i++){
    scanf("%d",&length[i]);
  }
  
  
  for(i=1; i<=N; i++){
    for(j=N; j>i; j--){
      if(length[j] < length[j-1]){
      change=length[j-1];
      length[j-1]=length[j];
      length[j]=change;
      count++;
      }
    }
  }
  
  for(i=1; i<=N; i++){
    printf("%d",length[i]);
    if(i < N)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
