#include <stdio.h>

void insertionSort();
void output();

int main(){

  int i,j,N;
  int A[1000];

  scanf("%d",&N);
  for( i=0 ; i<N ; i++) scanf("%d",&A[i]);

  output(N,A);
  insertionSort(N,A);

  return 0;
}

void insertionSort(int N, int A[]){
  //change the place

  int i, j, v;

  for(i=1; i <N;i++){
    
    v =A[i];
    j = i -1;
    while( j >=0 && A[j] >v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] =v;
    output(N,A);
  }
}

void output(int N,int A[]){
  //output

  int i;

  for( i=0; i<N; i++){
    
    if( i>0 ) printf(" ");
    
    printf("%d",A[i]);
  }
  printf("\n");
}
