#include<stdio.h>

void output(int A[],int N);
void insertionSort(int A[],int N);

int main(void)
{
  int A[100];
  int N;
  int i,j;

  scanf("%d",&N);
  
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }

  output(A,N);
  insertionSort(A,N);

  return 0;
}


void output(int A[],int N){
  int i = 0;
  
  while(i < N){
    if(i > 0){
      printf(" ");
    }
    printf("%d",A[i]);
    i++;
  }
  printf("\n");
}

void insertionSort(int A[],int N){
  int i,j;
  int v = 0;

  for(i = 1;i < N;i++){
    v = A[i];
    j = i - 1;
    
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = v;
    output(A,N);
  }
}

