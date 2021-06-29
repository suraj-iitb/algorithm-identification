#include<stdio.h>

int selectionsort(int A[],int N){
  int i,j,tmp;
  int k = 0;
  int minj;
  for(i = 0;i<N-1;i++){
    minj = i;
    for(j = i;j<=N-1;j++){
      if(A[j] < A[minj])
        minj = j;
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(i != minj)k++;/*iとminjが異なる*/
  }
  return k;
}

int main(){
  int A[100];
  int N,i,k;


  scanf("%d",&N);

  for(i = 0;i<N;i++){

    scanf("%d",&A[i]);
  }

  k = selectionsort(A,N);
    for(i = 0;i<N;i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",k);

  return 0;
}
