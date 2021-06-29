#include <stdio.h>

int main(){
  int i, j, temp, N, A[100], num=0, mini;
  
  // input
  scanf("%d",&N);
  for(i = 0; i <= N-1; i++)
    scanf("%d",&A[i]);
  
  
  // sort
  for(i = 0; i <= (N-1); i++){
    mini = i;
    for(j = i; j <= (N-1); j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
    if(A[i] == A[mini]){
      num--;
    }
  temp = A[i];
  A[i] = A[mini];
  A[mini] = temp;
	num++;
	
  }  

  
  // output
  for(i = 0; i <= N-1; i++){
    if(i == N-1)
      printf("%d",A[i]);
    else
      printf("%d ",A[i]);
    
  }
  printf("\n");
  printf("%d\n",num);
  return 0;
  
} 
