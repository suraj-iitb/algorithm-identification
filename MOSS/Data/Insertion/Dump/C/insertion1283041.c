#include <stdio.h>
#include <stdlib.h>
int main(){
  int A[1000];
  int i,j,v,k;
  int N;
  scanf("%d",&N);
  if (N > 100 || N <0)exit(1);
  for (i = 0; i < N; i++){
    scanf("%d",&A[i]);
   
}

 
  for (i = 0; i < N; i++){
    
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] >v){
     
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }

     for (k = 0; k < N-1; k++){
    printf("%d ",A[k]);
}
     printf("%d",A[k]);
     printf("\n");
  }
  return 0;
}
