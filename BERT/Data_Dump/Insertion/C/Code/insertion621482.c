#include<stdio.h> 

int main(){
  int j,i,N,key;
  int A[100];

  scanf("%d",&N); /*the number of elements*/
  for(j=0; j<N; j++){
    /* insert A[j] into the sorted sequence A[1,...,j-1] */
    scanf("%d",&A[j]);
  }

  /*The output first line*/
  for(j=0; j<N; j++){
    printf("%d",A[j]);
    if(j < N-1){
      printf(" ");
    }
  }
  printf("\n");

  for(j=1; j<N; j++){
    key=A[j];
    i=j-1;
    while((i >= 0) && (A[i] >key)){
      A[i+1]=A[i];
      i=i-1;
    }  
    A[i+1]=key;
    
    for(i=0; i<N; i++){
      printf("%d",A[i]);
      if(i < N-1){
	printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
