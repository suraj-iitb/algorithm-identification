#include<stdio.h>

int main(){
  int i,j,k,key,N,A[100];
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(k=0;k<N;k++){
    if(k>=1) printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  
  for(i=1;i<N;i++){
    key=A[i];
    j=i-1;
    
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j=j-1;
    }
    A[j+1]=key;
    
    for(k=0;k<N;k++){
      if(k>=1) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }
  
  return 0;
}
