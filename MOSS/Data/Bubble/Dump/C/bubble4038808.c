#include <stdio.h>

int main(){
  int N,A[100],i,j,cg,flag = 1,k,count=0;

  scanf("%d",&N);

  for(i = 0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }
  while(flag == 1){
    flag = 0;
    for(j = N-1 ; j>0 ; j--){
      if(A[j] < A[j-1]){
	cg = A[j];
	A[j] = A[j-1];
	A[j-1] = cg;
	flag = 1;
	count++;
      }
    }
  }
  
  for(k=0;k<N;k++){
    printf("%d",A[k]);
      if(k == N-1) break;
      printf(" ");
  }
  printf("\n");

  printf("%d\n",count);
}

