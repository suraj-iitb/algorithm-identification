#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,key,A[105],j,n;
  scanf("%d",&N);
  //  A=(int*)malloc(N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){  
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(n=0;n<N;n++){
      printf("%d",A[n]);
      if(n<N-1)
	printf(" ");
    }
    printf("\n");
  }
  //  free(A);
  return 0;
}
