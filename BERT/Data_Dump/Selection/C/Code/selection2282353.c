#include<stdio.h>
#include<stdlib.h>

int main(){
  int N, i, j, tmp, minj,  t=0;
  int A[100];

  scanf("%d",&N);
  if( N<1 || 100<N ) exit(1);

  for( i=0 ; i<N ; i++ ){
    scanf("%d",&A[i]);
    if( A[i]<0 || 100<A[i] ) exit(1);
  }

  for( i=0 ; i<N ; i++ ){
    minj = i;

    for( j=i ; j<N ; j++ ){
      if( A[j] < A[minj] ) minj = j;
    }

    if(minj != i){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      t++;
    }
  }

  for( i=0 ; i<N-1 ; i++ ){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",t);

  return 0;
}
