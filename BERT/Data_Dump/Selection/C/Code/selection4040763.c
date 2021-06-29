#include<stdio.h>
void selectionSort(int *,int);
int count = 0;
int main(){
  int N,A[100];
  int i;
  scanf("%d",&N); //数列の長さ
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);
    for(i = 0;i < N; i++){
      printf("%d",A[i]);
      if(i != N-1){
      printf(" ");
    }
    }
  printf("\n%d\n",count);
  }
void selectionSort(int *A,int N){
  int i,j,tmp,minj;
  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(A[j]<A[minj]){
        minj = j;
      }
    }
    if(A[i] == A[minj]){
    }else{
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count++;
  }
  }
}

