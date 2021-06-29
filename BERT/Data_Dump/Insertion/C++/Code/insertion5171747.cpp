#include <stdio.h>

main(){

  int i = 0, j = 0, k = 0;
  int A[100];
  int N = 100;
  int key = 0;
  
  scanf("%d",&N);
  
  for (i=1;i<=N;i++){
    scanf("%d",&A[i]);
  }
    
  for (i=1;i<=N;i++){
    key = A[i];
    j = i - 1;
    while ((j>0) && (A[j]>key)){
      A[j+1] = A[j];
      j = j - 1;
    }
    A[j+1] = key;
    for (k=1;k<=N;k++){
      printf("%d",A[k]);
      if(k<N){
	printf(" ");
      }
    }
    printf("\n");
  }

}
