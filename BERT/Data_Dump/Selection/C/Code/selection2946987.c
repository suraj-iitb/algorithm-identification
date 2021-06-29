#include <stdio.h>
#define N 100

int main(){
  int A[N];
  int num, i, j, minj, temp;
  int count = 0;

  scanf("%d", &num);
  
  for(i = 0; i < num; i++){
    scanf("%d", &A[i]);
  }
  
  for(i = 0; i < num; i++){
    minj = i;
    for(j = i; j < num; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    
    if(i != minj){
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      
      count++;
    }
  }
  for(i = 0; i < num-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num-1]);
  printf("%d\n",count);
  return 0;
}

