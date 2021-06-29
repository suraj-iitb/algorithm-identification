#include<stdio.h>

int main(){
  int k,v,N,i,j,A[1000];
  scanf("%d",&N);
  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k<N-1){
    printf(" ");
    }
    }
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    printf("\n");
    A[j+1]=v;
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k<N-1){
      printf(" ");
      }
    }
   
  }
  printf("\n");
  return 0;
}
  

