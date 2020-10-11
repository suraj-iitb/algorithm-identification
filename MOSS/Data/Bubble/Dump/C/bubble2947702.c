#include<stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(){
  
  int N,i,j,flag,count=0;
  scanf("%d",&N);
  
  int A[N];
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  flag = 1;

  while(flag){
    flag=0;
      for(j=N-1; j>=1; j--){
	if(A[j] < A[j-1]){
	  swap(&A[j],&A[j-1]);
	  flag = 1;
	  count++;
	}
      }
  }
  
  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
  return 0;
}



