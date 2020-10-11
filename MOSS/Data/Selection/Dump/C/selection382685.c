#include<stdio.h>
int main(void){
  int A[100],temp=0,count=0,mini=0,N,i,j;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0 ; i < N ; i++){
    mini = i;
    for(j = i+1 ; j < N ; j++){
      if(A[j] < A[mini]){
	mini = j;
      }         
    }
    temp = A[i];
    A[i] = A[mini];
    A[mini] = temp;
    if(A[i] != A[mini]) count++;
  }
  
  for(j = 0 ; j < N ; j++){
    printf("%d",A[j]);
    if(j < N-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}
