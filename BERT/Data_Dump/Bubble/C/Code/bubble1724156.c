#include<stdio.h>

#define MAX 100

void Bubble(int N,int *A){

  int i;
  int cnt = 0;
  int temp;
  int flag;

  flag = 1;
  while(flag){
    flag = 0;
    for(i = N-1;i >=1;i--){
      if(A[i] < A[i-1]){
	temp = A[i];
	A[i] = A[i-1];
	A[i-1] = temp;
	cnt++;
	flag = 1;
      }
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

  Bubble(num,A);

  return 0;
}
