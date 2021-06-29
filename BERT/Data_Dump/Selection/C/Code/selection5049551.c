#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,*A,i,j,data,minj,cnt=0;
  
  scanf("%d", &N);

  A = malloc(sizeof(int)*N);

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if( A[j] < A[minj] ) {
	minj = j;
      }
    }
    data = A[i];
    A[i] = A[minj];
    A[minj] = data;
    if(minj != i)cnt++;
  }

    for(i = 0; i < N; i++){
      printf("%d", A[i]);
      if(i != N-1)printf(" ");
    }
    printf("\n");
    printf("%d\n", cnt);
    
    return 0;
}


