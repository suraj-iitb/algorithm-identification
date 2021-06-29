#include <stdio.h>
#include <stdlib.h>

void CountingSort(int);

#define MAX 10000
int *A,*B,C[MAX+1];
int N;

int main(){
  int i,j;
  scanf("%d",&N);
  A=(int*)malloc(sizeof(int) * N+1);
  for(i=0;i<N;i++){
    scanf("%d",&A[i+1]);
  }
  B=(int*)malloc(sizeof(int) * N+1);


  CountingSort(MAX);

  for (i=1;i<=N;i++){
    if (i>1){
      printf(" ");
    }
    printf("%d", B[i]);
  }
  printf("\n");

  free(A);
  free(B);

  return 0;
}

void CountingSort(int k){
  int i,j;

  for(i=0;i<k;i++){
    C[i] = 0;
  }
  /* C[i] ??? i ???????????°????¨?????????? */
  for(j=1;j<=N;j++){
    C[A[j]]++;
  }

  /* C[i] ??? i ??\????????°???????????°????¨??????????*/
  for( i = 1; i <=k; i++ )
  {
    C[i] = C[i] + C[i-1];
  }
  for ( j = N; j >= 1; j-- ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
