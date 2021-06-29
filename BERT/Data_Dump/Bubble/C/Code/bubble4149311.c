#include<stdio.h>
void swapSort(int *x,int *y){
  int temp;
  temp = *x;
  *x =*y;
  *y = temp;
}
int bubbleSort(int A[], int N){
  int i,j;
  static int count =0;
  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swapSort(&A[j],&A[j-1]);
	count=count+1;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
}

int main(){
  int A[100],N,i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,N);
  return 0;
}

