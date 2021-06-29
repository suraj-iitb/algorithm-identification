#include <stdio.h>

int main(){
  int i, j, count = 0, A[100], minj, N, temp;
  
  //input
  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  
  //sort
  for(i = 0; i < N; i++){
    minj = i;
    
    for(j = i; j < N; j++){
      if(A[j] < A[minj]) minj = j;
    }
    
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(i != minj) count++;
  }

  //output
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }

  printf("%d\n%d\n",A[i],count);

  return 0;
}


