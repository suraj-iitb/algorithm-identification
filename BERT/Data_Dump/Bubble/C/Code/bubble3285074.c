#include <stdio.h>

int main(){
  int N,A[100];
    int i,j,flag,temp;

  scanf("%d",&N);
  if(1 <= N && N <= 100 ){
    for (j=0;j<N;j++){
      scanf("%d",&A[j]);
	}
  flag = 1;
  
  while (flag != 0){
    flag = 0;
   for (j =N-1;j>=1;j--){

    if(A[j] < A[j-1]){
      temp = A[j];
      A[j] = A[j-1];
      A[j-1] = temp;
      flag = 1;
      i++;
    }
   }
  }

  for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d",A[N-1]);
  printf("\n");
  printf("%d",i);
  printf("\n");
    }
return 0;
}
