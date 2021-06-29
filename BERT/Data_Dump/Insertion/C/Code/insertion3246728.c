#include <stdio.h>

int main(void){

  int N,A[1000];
  scanf("%d",&N);
  int k;
  for(k=0;k<N;k++) {
    scanf("%d",&A[k]);
  }
  int i;
  for(i=0;i<N;i++){
    int v=A[i];
    int j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      A[j]=v;
      j--;
    }
    for(k=0;k<N;k++) {
      printf("%d",A[k]);
      if(k != N-1){
	printf(" ");
      }
    }
    printf("\n");
  }
  return 0;

}
