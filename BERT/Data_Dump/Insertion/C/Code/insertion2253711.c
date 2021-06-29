#include<stdio.h>
#define B 1000
int main()
{
  int i,v,N,j,b;
  int A[B];
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for( i=0; i<N ; i++){
    v = A[i];
    j = i -1;
    while( j>= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(b=0; b<N-1; b++){
      printf("%d ",A[b]);
    }
    printf("%d\n",A[b]);
  }
  return 0;
}
