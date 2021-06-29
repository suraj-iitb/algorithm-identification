#include <stdio.h>

int main(){
  int i,j,N,A[100000],v;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(i>=1) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");  
  for(j=1;j<N;j++){
    v=A[j];
    i=j-1;
    while(i>=0&&A[i]>v){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=v;
    for(i=0;i<N;i++){
      if(i>=1) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
  }
  return 0;
}

