#include<stdio.h>
#define a_len 1000

int main(){
  int i,j,N,key,r;
  int A[a_len];

  scanf("%d",&N);

  for(r=0; r<N; r++){
    scanf("%d",&A[r]);
    printf("%d",A[r]);
    if(r != N-1){
	printf(" ");
      }
  }

  printf("\n");


  for(i=1; i<N; i++){
    key = A[i];
    j = i - 1;
    while(j>=0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;

    for(r=0; r<N; r++){
      printf("%d",A[r]);
      if(r != N-1){
	printf(" ");
      }
    }
    printf("\n");
    
  }

  return 0;
  
}

