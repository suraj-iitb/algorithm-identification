#include <stdio.h>
#define G 1000
#define MAX 100

void printArray(int A[],int n){
  int i;

  /*    for(i = 0;i <= n - 2 ;i++){
    
	printf("%d ",A[i]);

    }
    printf("%d\n",A[i]); */

  for(i = 0;i<n ;i++){
    
    if(i>0) printf(" ");

    printf("%d",A[i]);

    }
  printf("\n");

}




int main(){

  int i,v,j,n,a,b=0;

  int A[G];

  scanf("%d",&n);


  for(i = 0;i <= n - 1;i++){

    scanf("%d",&A[i]);

    if(A[i] > G )  printf("error\n");
    
  }
  printArray(A,n);


  for(i = 1;i <= n - 1;i++){

    v = A[i];

    j = i - 1;

    while(j >= 0 && A[j] > v){

      A[j+1] = A[j];

      j--;

    }

      A[j+1] = v;

      printArray(A,n);

  }

  return 0;

}

