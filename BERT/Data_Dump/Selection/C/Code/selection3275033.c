#include <stdio.h>

int main(){
  int N,i,j,a,minj,A[100],c=0;

  scanf("%d",&N);

  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i < N; i++){  
    minj = i;  
    for(j=i; j < N; j++){    
      if(A[j] < A[minj]){
	minj = j;
      }  
    }
    if(minj != i){
      c++;
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
  }
  
  for(i=0; i < N; i++){
    printf("%d",A[i]);
    if(i != N-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",c);
  
  return 0;
}

