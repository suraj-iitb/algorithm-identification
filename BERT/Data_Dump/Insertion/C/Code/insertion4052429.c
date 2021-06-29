#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  int A[1000];
  int v;
  int i,j;

  scanf("%d",&N);
  if(N <= 0 || 101 <= N) exit(0);
  
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(j=0;j<N-1;j++)printf("%d ",A[j]);
    printf("%d",A[j]);
    
    printf("\n");
  }
  return 0; 
}

