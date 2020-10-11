#include <stdio.h>

void bubbleSort(int [], int);

int main(){
  int N,A[100];
  int i;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A, N);// N 個の要素を含む 0-オリジンの配列 A
  return 0;
}

void bubbleSort(int A[],int N){
  int i,j,tmp,k,count=0;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      //ソートを入れ替える
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	//入れ替えた回数を足す
	count++;
      }
    }
  }

  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}
    

