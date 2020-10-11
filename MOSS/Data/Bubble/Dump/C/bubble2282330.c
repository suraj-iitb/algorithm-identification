#include<stdio.h>
#include<stdlib.h>

int main(){
  int N, i, j, t=0, tmp;
  int A[100];

  scanf("%d",&N);
  if( N<0 || 100<N ) exit(1);

  for( i=0 ; i<N ; i++ ){
    scanf("%d",&A[i]);
    if( A[i]<0 || 100<A[i] ) exit(2);
  }

  for( i=0 ; i<N ; i++ ){
    for( j=N-1 ; i<j ; j-- ){
      if( A[j]<A[j-1] ){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	t++;
      }
    }
  }

  for( i=0 ; i<N-1 ; i++ ){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",t);
      
  return 0;
}
