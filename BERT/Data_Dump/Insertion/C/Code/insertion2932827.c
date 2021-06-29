#include<stdio.h>

int main(){
  int i,j,N,v;
  int A[1000];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j+1==N)break;
      printf(" ");
    }
  printf("\n");

  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  
    for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j+1==N)break;
      printf(" ");
    }
    printf("\n");
  }
  
  return 0;
}

