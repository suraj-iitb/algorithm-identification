#include<stdio.h>

#define MAX 100

void Selection(int N,int *A){

  int i;
  int j;
  int min;
  int cnt = 0;
  int temp;

  for(i = 0;i < N;i++){

    min = i;
    for(j = i;j < N;j++){
      if(A[j] < A[min]){
	min = j;
      }
    }
    if(min != i){
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
      cnt++;
    }
  }

  for(i = 0;i < N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
}

int main(){

  int i;
  int num;
  int A[MAX];

  scanf("%d",&num);

  for(i = 0;i < num;i++){
    scanf("%d",&A[i]); 
  }

  Selection(num,A);

  return 0;

}
