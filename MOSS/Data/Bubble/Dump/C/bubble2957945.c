#include <stdio.h>

void bubbleSort(int *,int);

int main(){
  int i,N;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  bubbleSort(A,N);
  return 0;
}

void bubbleSort(int *A,int N){
  int flag = 1; // 逆の隣接要素が存在する
    int j,x,count=0;
    while(flag){
      flag = 0;
	for(j=N-1;j>0;j--){
	  if(A[j] < A[j-1]){
	    x = A[j];
	    A[j]=A[j-1];
	    A[j-1]=x;
	    flag = 1;
	    count++;
	  }
	}
    }
    for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j!=N-1)printf(" ");
    }
    printf("\n%d\n",count);
}

