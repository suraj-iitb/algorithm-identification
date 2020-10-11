#include <stdio.h>
int bubbleSort(int[],int);
int main(){

int i,j,N;

scanf("%d",&N);
int A[N];
for(i = 0; i < N; i++){
  scanf("%d",&A[i]);
}
  bubbleSort(A,N);
  return 0;
}

int bubbleSort(int A[ ],int N){
  int i,j,tmp;
  int flag;
  int count = 0;
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j = N-1; j>= i+1; j--){
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
    i++;
  }
  for(i = 0; i < N; i++){
  if(i){
    printf(" ");
  }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
}
