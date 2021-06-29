#include <stdio.h>

int main(){

  int i,j;
  int minj,count =0;
  int N,temp;
  int flag;
  int A[100];
  
  scanf("%d",&N);

  for(i = 0; i < N ; i++)
    scanf("%d",&A[i]);

  for( i = 0 ; i < N ; i++){
    minj = i;
    flag = 0;

    for(j = i; j < N ; j++){
      if (A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }

    if (flag ==1){
      
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count++;

    }
  }

  //output

  for( i = 0;i < N; i++){
    printf("%d",A[i]);
    
  if(i<N-1) printf(" ");
}
  printf("\n");
  printf("%d\n",count);

    return 0;
}
