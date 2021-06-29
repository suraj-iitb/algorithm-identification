#include <stdio.h>

int main(){
  int i,j=0,N=0,v,x;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++)   scanf("%d",&A[i]);
  for(i=0;i<N-1;i++)  printf("%d ",A[i]);
  
  printf("%d",A[N-1]);
  printf("\n");

  for(i=1;i<N;i++){
    v = A[i];
    j=i-1;

    while(j >=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(x=0;x<N-1;x++){
      printf("%d ",A[x]);
    }

    printf("%d",A[N-1]);
    printf("\n");
  }

  return 0;
}
	   
    

