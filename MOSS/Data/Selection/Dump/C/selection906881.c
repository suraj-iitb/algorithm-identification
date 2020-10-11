#include<stdio.h>

void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void print(int* A, int N){
  int i;
  for(i = 0; i < N; i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

int selection_sort(int* A, int N){
  int i,j,cnt=0;
  
  for(i = 0; i < N; i++){
    int mini = i;
    for(j = i; j < N; j++) if(A[j] < A[mini]) mini = j;
    cnt += (i==mini?0:1);
    swap(&A[i],&A[mini]);
  }
  print(A,N);
  return cnt;
}

int main(){
  int i,N,data[100];
  scanf("%d",&N);
  for(i = 0; i < N; i++) scanf("%d",&data[i]);
  printf("%d\n",selection_sort(data,N));
  return 0;
}
