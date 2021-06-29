#include <stdio.h>
int main(){
  int i,N,A[100],j,count=0,tmp,min=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]); 
  }
  for(i=0;i<N-1;i++){
    min =i;
    for(j=i;j<N;j++){
      if(A[j] < A[min]){
	min =j;
      }
     }
    if(min != i) count++;
    
    tmp = A[i];
    A[i] = A[min];
    A[min] = tmp;
  }
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
