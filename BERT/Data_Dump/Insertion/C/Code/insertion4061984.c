#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, j, k, N, key;
  int A[100];
  
  scanf("%d",&N);
  if(N < 1 || N > 100){
    fprintf(stderr,"Please enter the number of elements in the range from 1 to 100.(1st line)\n");
    exit(1);
  }
    
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
    
    if(A[i] < 0 || A[i] > 1000){
      fprintf(stderr,"Please enter the element in the range from 0 to 1000. (2nd line :%d)\n",i+1);
      exit(2);
    }
  }

  for(k = 0; k < N-1; k++){
      printf("%d ",A[k]); 
    }
    printf("%d\n",A[k]);
    
  for(i = 1; i < N; i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;

    for(k = 0; k < N-1; k++){
      printf("%d ",A[k]); 
    }
    printf("%d\n",A[k]);

  }

  return 0;
}
