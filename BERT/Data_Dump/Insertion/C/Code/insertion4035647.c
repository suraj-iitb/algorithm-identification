#include <stdio.h>

int main(){

  int A[1000],N,i,j,k,v;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i == N-1) break;
    printf(" ");
  }

  printf("\n");
  
  for(i=1;i<N;i++){

    v = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > v){

      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k == N-1) break;
      printf(" ");
    }
    printf("\n");
    
  }

  return 0;
}
    
  
