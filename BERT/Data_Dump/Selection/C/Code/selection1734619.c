#include <stdio.h>
int main(){
  int i, j, minj, temp, N, c=0;
  int A[100]={};

  scanf("%d",&N);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]>A[minj]){
    temp = A[minj];       
    A[minj] = A[i];
    A[i]= temp;
    c++;
    }
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
      }
  printf("%d",A[N-1]);
  printf("\n%d\n",c);

  return 0;
}
