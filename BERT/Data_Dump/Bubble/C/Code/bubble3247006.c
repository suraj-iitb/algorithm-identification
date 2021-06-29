#include <stdio.h>

int main(void){

  int N,A[100];
  scanf("%d",&N);
  int k;
  for(k=0;k<N;k++) {
    scanf("%d",&A[k]);
  }
  int i,j;
  int count=0;
  for(j=N-1;j>0;j--){
    for(i=0;i<j;i++){
      int v = A[i];
      if(A[i]>A[i+1]){
	A[i]=A[i+1];
	A[i+1]=v;
	count++;
      }
    }
  }
  for(k=0;k<N;k++) {
    printf("%d",A[k]);
    if(k != N-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;

}
