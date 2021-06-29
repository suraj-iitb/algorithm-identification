#include <stdio.h>

int main(){
  int i, j, temp, N, A[100], num=0;
  
  // input
  scanf("%d",&N);
  for(i = 0; i <= N-1; i++)
    scanf("%d",&A[i]);
  
  
  // sort
  for(i = 0; i < (N-1); i++){
    for(j = (N-1); j > i; j--){
      if(A[j-1] > A[j]){
	temp = A[j-1];
	A[j-1] = A[j];
	A[j] = temp;
	num++;
      }
    }
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
