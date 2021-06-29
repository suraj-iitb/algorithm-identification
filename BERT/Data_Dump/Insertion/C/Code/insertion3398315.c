#include <stdio.h>

void insertionSort(int A[],int N){
  int i,j,v;
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;

    for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j!=N-1) printf(" ");
    }
    printf("\n");
  }
}

int main(void){
  int N,i;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  insertionSort(A,N);
  return 0;
}
