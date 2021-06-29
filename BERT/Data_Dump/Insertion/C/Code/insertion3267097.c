#include<stdio.h>

int main(){
  
  int i,j,v,N,a;
  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<=N;i++){
    for(a=0;a<N;a++){
    printf("%d",A[a]);
    if(a < N -1){
      printf(" ");
    }
    }
    printf("\n");
    v = A[i];
    j = i -1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  return 0;
}
      
  

