#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(){
  int N,*A,i,j,k,count=0,minj;
  scanf("%d",&N);
  A=(int *)malloc(sizeof(int)*N);

  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    if(minj!=i){
      swap(&A[i],&A[minj]);
      count++;
    }
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

void swap(int *x,int *y){
  int tmp;
  tmp=*x;
  *x=*y;
  *y=tmp;
}

