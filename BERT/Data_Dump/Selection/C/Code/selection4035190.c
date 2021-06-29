#include <stdio.h>

int SelectSort_Scount(int *, int);

int main(){
  int i,N,SwapCount;
  int A[100];

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  SwapCount = SelectSort_Scount(A,N);

  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i==N-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",SwapCount);

  return 0;
}

int SelectSort_Scount(int *A, int len){
  int i,j,tmp,min,Scount=0;

  for(i=0; i<=len-1; i++){
    min = i;
    for(j=i+1; j<=len-1; j++){
      if(A[min] > A[j]){
	min = j;
      }
    }
    if(A[i] != A[min]){
      tmp = A[i];
      A[i] = A[min];
      A[min] = tmp;
      Scount++;
    }
  }

  return Scount;
}

