#include <stdio.h>

int BubbleSort_Scount(int *, int);

int main(){
  int N,i,SwapCount;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N; i++){
    scanf("%d",&A[i]);
  }

  SwapCount = BubbleSort_Scount(A,N);
  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i==N-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",SwapCount);
  return 0;
}

int BubbleSort_Scount(int *A, int len){
  int tmp,i,j,Scount=0;

  for(i=0; i<len-1; i++){
    for(j=len-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	Scount++;
      }
    }
  }

  return Scount;
}

