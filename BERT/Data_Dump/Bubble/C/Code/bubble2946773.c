#include<stdio.h>
#include<stdbool.h>
#define SWAP(type,a,b) { type temp = a; a = b; b = temp; }

int bubbleSort(int A[], int N){
  int sw = 0;
  int i, j;
  bool flag = 1;
  for( i = 0; flag ; i++){
    flag = 0;
    for( j = N -1; j >= i + 1 ; j--){
      if( A[j] < A[j-1] ){
        SWAP(int,A[j], A[j-1] );
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main(){
  int A[100], N, sw, end1, i;
  scanf("%d",&N);
  for( int i = 0; i < N; i++) scanf("%d", &A[i]);

  sw = bubbleSort( A, N);
  for(i = 0; i < N ; i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d", sw);
  printf("\n");

  return 0;
}

