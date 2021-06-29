#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);

int main(){
  int N,*A,i,j,flag,count=0;

  scanf("%d",&N);
  A=(int*)malloc(sizeof(int)*N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1;j>=i+1;--j){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	flag=1;
	count++;
      }
    }
    i++;
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

