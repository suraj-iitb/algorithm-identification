#include<stdio.h>
#include<stdlib.h>

int main(){
  int N, j, i, kazu,  flag = 1, count = 0;
  int *A;

  scanf("%d",&N);

  A = malloc(sizeof(int) * N);

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
    
  
  while(flag){
    flag = 0;
    for(j=N-1; j>0; j--){
      if(A[j]<A[j-1]){
	kazu = A[j];
	A[j] = A[j-1];
	A[j-1] = kazu;
	flag=1;
	count++;
      }
    }
  }

  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

  
  

