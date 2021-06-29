#include<stdio.h>
#define N 100

void insertionSort(int *,int);

int main(void){
  int num,A[N];
  int i;

  scanf(" %d",&num);
  for(i = 0; i < num; i++){
    scanf(" %d",&A[i]);
  }

  for(i = 0; i < num-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num-1]);

  insertionSort(A,num);
  
  
  return 0;
}

void insertionSort(int *A, int num){
  int i,j;
  int tmp;

  for(i = 1; i < num; i++){
    tmp = A[i];
    j = i -1;
    while(j >= 0 && A[j] > tmp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = tmp;

    for(j = 0; j < num-1; j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[num-1]);
  }

}

