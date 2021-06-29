#include <stdio.h>

int main(){
  int i,j,v,N,l=0;
  int A[1000];
  scanf("%d",&N);
  for(i=0;i < N;i++){
    scanf("%d",&A[i]);
  }  
  for(i=0;i < N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]); 
  for(i=1;i <= N-1;i++){
    v=A[i];
    j=i-1;
    while(j >=0 && A[j] > v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(l=0;l < N-1;l++){
      printf("%d ",A[l]);
    }
    printf("%d\n",A[l]);
  }
  return 0;
}

