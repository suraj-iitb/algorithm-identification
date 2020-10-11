#include<stdio.h>

int BubbleSort(int A[],int N){
  int i,j,count=0,tmp;
    for(i = 0 ; i < N-1 ; i++){
    for(j = N-1 ; j >= 1 ; j--){
      if(A[j] < A[j - 1]){
	tmp = A[j];
	A[j] = A[j - 1];
	A[j - 1] = tmp;
	count++;
      }
    }
  }
  return count;
}

int main(){
  int N,i,count;

  scanf("%d",&N);
  
  int A[N];

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  
  count = BubbleSort(A,N);

printf("%d",A[0]);
  for(i = 1 ; i < N ; i++){
    printf(" %d",A[i]);
  }
  
  printf("\n");
  printf("%d\n",count);

  return 0;
}
