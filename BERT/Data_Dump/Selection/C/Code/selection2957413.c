#include<stdio.h>
#define MAX 100
int main(){
  int i,j,minj,tmp,N;
  int A[MAX];
  int count = 0;
  
  scanf("%d",&N);
  for( i=0 ; i<N ; i++ )
    scanf("%d",&A[i]);

  for( i=0 ; i<=N-1 ; i++ ){
    minj = i;

    for( j=i ; j<=N-1 ; j++ ){
      if(A[j] < A[minj])
	minj = j;
    }

    if(i != minj){
      count++;
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
    }
  }

    for( i=0 ; i<N-1 ; i++)
      printf("%d ",A[i]);
    printf("%d",A[N-1]);
    printf("\n%d\n",count);
  return 0;
}

