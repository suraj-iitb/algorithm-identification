#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[100], i, j, minj, count=0, N, tmp, a, b, min;

  scanf("%d",&N);
  if(N<1 || N>100) exit(1);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>100) exit(2);
  }

  for(i=0; i<N-1; i++){
    min=A[i];
    a=0;
    for(j=i; j<N; j++){
      if( min > A[j] ) {
	min = A[j];
	a=1;
	b=j;
      }
    }
    if(a==1){
      tmp = A[b];
      A[b] = A[i];
      A[i] = tmp;
      count++;
    }
  }


  for(i=0; i<N-1; i++) printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);

  return 0;
}

