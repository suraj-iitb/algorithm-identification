#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y);
int main(){
  int i,j,N,flag=1,*A,count=0;

  scanf("%d",&N);
  A=malloc(sizeof(int)*N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  
  free(A);
  return 0;
}
void swap(int *x,int *y){
  int a;
  a=*x;
  *x=*y;
  *y=a;
}
