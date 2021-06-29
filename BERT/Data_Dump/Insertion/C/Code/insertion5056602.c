#include<stdio.h>
#include<stdlib.h>


int main(){

  int N,v,j,i,z;

  int A[1000];

  scanf("%d",&N);

  if(N < 1 || N > 100)exit(0);

  for(i = 0;i < N;i++){

    scanf("%d",&A[i]);

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

  for(i = 1;i < N;i++){

    v = A[i];

    j = i - 1;

    while(j >= 0&&A[j] > v){

      A[j+1] = A[j];

      j--;

    
    }

     A[j+1] = v;

     for(z = 0;z < N;z++){

       if(z == N-1){

	 printf("%d",A[z]);

       }

       else{

	 printf("%d ",A[z]);

       }

     }


    printf("\n");


  }

  return 0;

}

  
  

    

