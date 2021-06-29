#include<stdio.h>
#include<stdlib.h>

int main(){

  int flag = 0,N,i,j,cnt = 0,flag2;

  int A[100];

  scanf("%d",&N);

  if(N < 1 || N > 100)exit(1);



  for(i = 0;i < N;i++){

    scanf("%d",&A[i]);

  }



  while(1){
    if(flag == N)break;

    for(j = N - 1;j > 0;j--){

      if(A[j] < A[j-1]){

	flag2 = A[j];

	A[j] = A[j-1];

	A[j-1] = flag2;

	

	cnt++;

      }


    }

    flag++;

  }

  for(i = 0;i < N;i++){

    if(i == N-1){

      printf("%d",A[i]);
    }

    else{
    

    printf("%d ",A[i]);

    }

    

  }

  printf("\n");

  printf("%d\n",cnt);

  return 0;
}

    

  

  

