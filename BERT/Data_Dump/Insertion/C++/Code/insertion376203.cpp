#include <stdio.h>

main(){

  int i = 0, j = 0, k = 0;
  int A[101];
  int N = 1;
  int key = 0;
  
  scanf("%d",&N);
  
  for (k=1;k<=N;k++){
    scanf("%d",&A[k]);
  }
    
  for (j=1;j<=N;j++){
    key = A[j];
    i = j - 1;
    while ((i>0) && (A[i]>key)){
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = key;
    for (k=1;k<=N;k++){
      printf("%d",A[k]);
      if(k<N){
	printf(" ");
      }
    }
    printf("\n");
  }

}
