#include <stdio.h>
int main(){
  int i,minj,j,A[100],N,temp,x=0,y;

  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N; i++){
    minj = i;
    y = 0;
    for(j = i; j < N; j++){
      if(A[j]<A[minj]){
	minj = j;
	y = 1;
      }
    }
    if(y == 1){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    x++;
    }
  }
    
    for(j = 0; j < N; j++){
    printf("%d",A[j]);
    if(j != N-1) printf(" ");
  }
  printf("\n");

  printf("%d\n",x);

  return 0;
}

