#include<stdio.h>
int main(void){
  int N,A[100],i,j,count=0,key=0;
  
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < N ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j] < A[j-1]){
	key = A[j];
	A[j] = A[j-1];
	A[j-1] = key;
	count++;
      }
    }
  }
  for(j = 0 ; j < N ; j++){
    printf("%d",A[j]);
    if(j < N-1){
      printf(" ");
    }  
  }
  printf("\n%d\n",count);
  return 0;
}
