#include <stdio.h>

int main(){
  int A[100],N,i,j,k,minj = 0,cg,count = 0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i<N ;i++){
    minj = i;
    for(j = i ; j < N ; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    cg = A[i];
    A[i] = A[minj];
    A[minj] = cg;
    if(minj != i) count++;
  }
  
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k == N-1) break;
    printf(" ");
  }
  printf("\n");

  printf("%d\n",count);
  
  return 0;
}


