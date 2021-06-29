#include <stdio.h>

int main(){
  int i,A[100],N,aLen=0,j,tmp,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 
   
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	count++;
      }
    }
  }
  
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0; 
}
