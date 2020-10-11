#include <stdio.h>

int main(){
  int i,j,z,N,A[100],count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
 }
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	z=A[j];
	A[j]=A[j-1];
	A[j-1]=z;
	count++;
      }
	
    }
  }
  for(i=0;i<N-1;i++)printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n%d\n",count);
  
  return 0;
}

