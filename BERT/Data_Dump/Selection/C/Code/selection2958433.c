#include<stdio.h>

void swap(int *x, int *y){
  int temp=*x;
  *x = *y;
  *y = temp;
}
    
int main(){
  
  int N,i,j,count=0,minj;
  scanf("%d",&N);
  
  int A[N];
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]!=A[minj]){
      swap(&A[i],&A[minj]);
      count++;
    }
  }
  
  
  
  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
  return 0;
}


