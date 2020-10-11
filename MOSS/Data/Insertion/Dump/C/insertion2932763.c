#include <stdio.h>

int main(){
  int i=0;
  int N;
  int v, j,b;
  int A[1000];
  
  while(1){
    scanf("%d",&N);
    if(N<101 && N>0){
      break;
    }
    printf("Error\n");
  }

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=1; i<N; i++){
    for(b=0; b<N-1; b++){
      printf("%d ",A[b]);
    }
    printf("%d\n",A[N-1]);
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=v;
  }
  
  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
    }
  printf("%d\n",A[N-1]);
  
  return 0;
}

