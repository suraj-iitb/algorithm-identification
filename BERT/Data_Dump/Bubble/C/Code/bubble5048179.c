#include <stdio.h>

void swap(int *x,int *y){
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

int main(){
  int i,j,k,N;
  int count=0;

  scanf("%d",&N);

  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    for(j=0;j<N-1;j++){
      for(k=N-1;k>=j+1;k--){
	if(A[k]<A[k-1]){
	  swap(&A[k],&A[k-1]);
	  count += 1;
	}
      }
    }
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d",A[i]);
    }
    else printf("%d ",A[i]);
  }

  printf("\n%d\n",count);
  
  return 0;
}

