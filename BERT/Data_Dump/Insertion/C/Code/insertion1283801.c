#include <stdio.h>
#define MAX 1000

main(){
  
  int i,j,v,N;
  int A[MAX];
  
  scanf("%d",&N);
  if(1>N && N>100) printf("error\n");
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[j]);

  for(i=1;i<N;i++){
    v = A[i];
    j = i-1;
    
    while(j >= 0 && A[j] > v){
      
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(j=0;j<N-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d",A[j]);
    printf("\n"); 
    
  }
  return 0;
}
