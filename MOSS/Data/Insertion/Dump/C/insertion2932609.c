#include <stdio.h>

#define N 100

int main(){

  int A[N]={0};
  int length, key;
  int i = 0, j = 0;
  
  scanf("%d", &length);
  while(i < length){
    scanf("%d", &A[i]);
    i++;
  }

  for(j = 0; j < length-1; j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[length-1]);
  
  for(i = 1; i < length; i++){
    key = A[i];
    j = i-1;
    
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = key;
    
    for(j = 0; j < length-1; j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[length-1]);
  }
  
  return 0;
}


