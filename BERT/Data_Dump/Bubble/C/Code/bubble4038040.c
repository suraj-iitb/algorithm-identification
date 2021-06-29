#include<stdio.h>

#define N 100

int bubbleSort(int *,int);

int main(void){
  int A[N],num,cnt;
  int i;

  scanf(" %d",&num);
  
  for(i = 0; i < num; i++){
    scanf(" %d",&A[i]);
  }

  cnt = bubbleSort(A,num);

  for(i = 0; i < num-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num-1]);

  printf("%d\n",cnt);
  
  return 0;
}

int bubbleSort(int *A, int num){
  int i,j;
  int flag=1,tmp,cnt=0;

  while(flag){
    flag = 0;
    for(i = num -1; i > 0; i--){
      if(A[i] < A[i-1]){
	tmp = A[i-1];
	A[i-1] = A[i];
	A[i] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }

  return cnt;
}
  

