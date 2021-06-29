
#include<stdio.h>


void selectionSort(int A[], int N){

  int i, j, k, min, count = 0;

  for( i = 0; i < N ; i++ ){

    min = i;

    for(j = i ; j < N; j++ ){

      if(A[j] < A[min]){
        min = j;
      }
    }
     k = A[i];
     A[i] = A[min];
     A[min] = k;
     if(i != min)count += 1;


  }

  space(A, N);

  printf("%d\n",count);

}


void space(int A[], int N){

  int i;

  for( i = 0; i < N; i++){

    if( i > 0 ){

      printf(" ");

    }

    printf("%d", A[i]);

  }

  printf("\n");

}


int main(void){

  int N, i, j;

  int A[100];

  

  scanf("%d", &N);

  for(i = 0; i < N; i++){

    scanf("%d", &A[i]);

  }

  selectionSort(A, N);

}
