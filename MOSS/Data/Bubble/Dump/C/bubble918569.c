#include<stdio.h>

void swap (int *x, int *y)
{
  int a;
  a=*x;
  *x=*y;
  *y=a;
}

int main(){
  int N,i,j;
  int A[100];
  int count=0;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
	count++;
      }
    }
  }
  
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}
