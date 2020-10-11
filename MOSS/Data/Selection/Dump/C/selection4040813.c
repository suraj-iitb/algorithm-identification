#include <stdio.h>
#define NMAX 100

int selectionSort(int *,int);
int main(void){
  int N,i,inp[NMAX],cnt;

  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%d",&inp[i]);
  }

  cnt = selectionSort(inp,N);
  for(i = 0;i < N;i++){
    if(i == N - 1){
      printf("%d\n",inp[i]);
    }else{
      printf("%d ",inp[i]);
    }
  }
  printf("%d\n",cnt);

  return 0;
}

int selectionSort(int *A,int N){

  
  int i,j,x,temp,cnt = 0;
  for(i = 0;i < N;i++){
    x = i;
    for(j = i;j < N;j++){
      if(A[j] < A[x]){
	x = j;
      }
    }
    if(i != x){
      temp = A[i];
      A[i] = A[x];
      A[x] = temp;
      cnt++;
    }
  }
  return cnt;
}

