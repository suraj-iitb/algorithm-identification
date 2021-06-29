#include<stdio.h>
#define NMAX 100

int count = 0;

void selectionSort(int[], int);
void output(int[], int);

int main(){

  int N, i, j;
  int A[NMAX];

  scanf("%d", &N);
  
  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);

  selectionSort(A, N);
  output(A, N);
  
  return 0;
}

void selectionSort(int A[], int N){

  int i, j, tmp, minj;
  
  for(i = 0; i <= N - 1; i++){
    
    minj = i;
    
    for(j = i; j <= N - 1; j++){
      
      if(A[j] < A[minj]){
	
	minj = j;
      }
    }
    
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
      
    if(A[i] < A[minj])count++;
  }
}
  

void output(int A[], int N){

  int i;

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);
}
  

