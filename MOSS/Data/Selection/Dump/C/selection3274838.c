#include<stdio.h>
int main(){
  int N,A[100],i,j,count=0,minj,B;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj =j;
      }
    }
    if(A[i] != A[minj]){
      B=A[i];
      A[i]=A[minj];
      A[minj]=B;
      count++;
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1)
      printf(" ");
    else printf("\n");
  }
  printf("%d\n",count);
  return 0;
}
      

