#include <stdio.h>
int main(){
  int flag,j,A[100],N,x=0,temp;

  scanf("%d",&N);
  for(j = 0; j < N; j++){
    scanf("%d",&A[j]);
  }
    
  flag = 1;
  while(flag){
    flag = 0;
    for(j = N-1; j >= 1; j--){
      if(A[j]<A[j-1]){
        temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	 x++;
      }
    }
  }
  
  for(j = 0; j < N; j++){
    printf("%d",A[j]);
    if(j != N-1) printf(" ");
  }
  printf("\n");

  printf("%d\n",x);

  return 0;
}

