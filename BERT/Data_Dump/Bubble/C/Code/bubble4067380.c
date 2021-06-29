#include <stdio.h>
void bubbleSort(int *, int);
int main(){
  int A[100],N=0;
  int i,j;
  
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  bubbleSort(A, N);
  
  return 0;
}

void bubbleSort(int *A, int N){
  int v=0,j=0,i;
  int t;
  int cnt=0;
  for(i=0; i<=N-1; i++){
    for(j = N-1; j >= 1; j--){
      if(A[j] < A[j-1]){
	v = A[j-1];
	A[j-1] = A[j];
	A[j] = v;
	cnt+=1;
      }
    }
  }
  for(t=0; t<N-1; t++){
    printf("%d ",A[t]);
  }
  if(t==N-1){
    printf("%d",A[t]);
  }
  printf("\n");
  printf("%d\n",cnt);
}

