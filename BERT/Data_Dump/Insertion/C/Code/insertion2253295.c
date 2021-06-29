#include <stdio.h>
int main(){
  int N,A[100],i,key,j;
  scanf("%d",&N);
  for(i = 0;i < N; i++ ){
    scanf("%d",&A[i]);
  }
  for(i = 0;i < N; i++ ){
    if(i >0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n"); 
  for(j = 1;j < N; j++ ){
    key = A[j];
    i=j-1;
    while(i >= 0 && A[i] > key){
      A[i+1] = A[i];
      i=i-1;
      A[i+1]=key;
    }
    for(i = 0;i < N; i++ ){
      if(i > 0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
  } 
  return 0;
}
