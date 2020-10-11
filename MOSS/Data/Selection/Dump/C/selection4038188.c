#include<stdio.h>

#define N 100

int selectionSort(int *,int);

int main(void){
  int A[N],num,cnt;
  int i;

  scanf(" %d",&num);
  for(i = 0; i < num; i++){
    scanf(" %d",&A[i]);
  }

  cnt = selectionSort(A,num);

  for(i = 0; i < num-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[num-1]);

  printf("%d\n",cnt);
  
  return 0;
}

int selectionSort(int *A, int num){
  int i,j;
  int min,tmp,cnt=0;

  for(i = 0; i < num; i++){
    min = i;
    for(j = i; j < num; j++){
      if(A[j] < A[min]){
	min = j;
      }
    }
    tmp = A[i];
    A[i] = A[min];
    A[min] = tmp;
    if(i != min) cnt++;
  }

  return cnt;
}
  
    

